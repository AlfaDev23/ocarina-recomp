// unzbic <in.nso> <out.nso>: rewrites a ZBIC-compressed NSO with raw segments. Compile with the source of github.com/kinnay/zbic (GPL-2.0) on the include path.
#define ZSTD_ZBIC_SUPPORT 1
#define ZSTDLIB_VISIBLE static
#define ZSTDLIB_HIDDEN static
#define ZSTDERRORLIB_VISIBLE static
#define ZSTDERRORLIB_HIDDEN static
#undef ZSTD_MULTITHREAD
#include "zstd.h"
#include "zstd.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static unsigned rd(const unsigned char *p) { unsigned v; memcpy(&v, p, 4); return v; }
static void wr(unsigned char *p, unsigned v) { memcpy(p, &v, 4); }

int main(int argc, char **argv) {
    if (argc != 3) return 2;
    FILE *f = fopen(argv[1], "rb");
    if (!f) return 3;
    fseek(f, 0, SEEK_END);
    long n = ftell(f);
    fseek(f, 0, SEEK_SET);
    unsigned char *in = malloc(n);
    if (fread(in, 1, n, f) != (size_t)n) return 4;
    fclose(f);
    unsigned char head[0x100];
    memcpy(head, in, 0x100);
    f = fopen(argv[2], "wb");
    if (!f) return 5;
    fwrite(head, 1, 0x100, f);
    unsigned pos = 0x100;
    for (int i = 0; i < 3; i++) {
        unsigned off = rd(in + 0x10 + i * 0x10), size = rd(in + 0x18 + i * 0x10), comp = rd(in + 0x60 + i * 4);
        unsigned char *out = malloc(size);
        size_t got = ZSTD_decompress(out, size, in + off, comp);
        if (ZSTD_isError(got) || got != size) { fprintf(stderr, "segment %d failed: %s\n", i, ZSTD_getErrorName(got)); return 6; }
        fwrite(out, 1, size, f);
        wr(head + 0x10 + i * 0x10, pos);
        wr(head + 0x60 + i * 4, size);
        pos += size;
        free(out);
    }
    wr(head + 0xC, rd(head + 0xC) & ~0xffu);
    fseek(f, 0, SEEK_SET);
    fwrite(head, 1, 0x100, f);
    fclose(f);
    printf("ok %u bytes\n", pos);
    return 0;
}
