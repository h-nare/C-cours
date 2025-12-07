#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define EOF (-1)
#define BUFSIZE 8

#define _WRITE 02
#define _ERR   020

typedef struct _iobuf {
    int  cnt;
    char *ptr;
    char *base;
    int  flag;
    int  fd;
} FILE;

int _flushbuf(int c, FILE *fp)
{
    int n;

    if ((fp->flag & _WRITE) == 0)
        return EOF;

    if (fp->base == NULL) {
        fp->base = malloc(BUFSIZE);
        if (fp->base == NULL)
            return EOF;
        fp->ptr = fp->base;
        fp->cnt = BUFSIZE;
    }

    n = fp->ptr - fp->base;
    if (n > 0)
        if (write(fp->fd, fp->base, n) != n)
            return EOF;

    fp->ptr = fp->base;
    fp->cnt = BUFSIZE;

    if (c == EOF)
        return EOF;

    *fp->ptr++ = c;
    fp->cnt--;
    return c;
}

int fflush(FILE *fp)
{
    return _flushbuf(EOF, fp);
}

int fclose(FILE *fp)
{
    fflush(fp);
    close(fp->fd);
    free(fp->base);
    return 0;
}

int main()
{
    FILE f;
    f.fd = creat("result.txt", 0666);
    f.flag = _WRITE;
    f.base = NULL;
    f.ptr = NULL;
    f.cnt = 0;

    _flushbuf('A', &f);
    _flushbuf('B', &f);
    _flushbuf('C', &f);

    fflush(&f);

    fclose(&f);

    return 0;
}

