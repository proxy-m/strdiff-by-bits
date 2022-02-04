#ifndef NULL
#define NULL 0
#endif

int getBit (unsigned char h, int pos) { // биты нумеруются справо налево (в двоичной арабской записи числа), а символы в строкаих идут слева направо
    return (h >> pos) & 1;
}

/**
 * Сравнение C-строк, завершающихся '\0'
 */
int strdiff (char *a, char *b) {
    if (a == NULL || b == NULL) { // что-то не инициализировано
        return -2; // здесь должна быть ошибка, потому что нельзя сравнить некорректный ввод
    } else if (a == b) { // указатель один и тот же (сама строка)
        return -1;
    }

    int wasLess = 0;
    int i = 0;
    while (a[i] != 0 && b[i] != 0 && a[i] == b[i]) {
        ++i;
    }
    if (a[i] != b[i]) {
        wasLess = 1;
    }

    int res = i*8; // bytes X 8
    int res0 = res; // мы стравниваем строки, хоть и побитово, но строки могут быть полностью равны только по байтам (нам нужно это значение, чтобы можно было вернуть -1 в конце для равных строк)

    if (wasLess != 0 && a[i] != 0 && b[i] != 0) {
        unsigned char hA = (unsigned char)a[i];
        unsigned char hB = (unsigned char)b[i];
        for (int j=0; j<8; ++j) {
            if (getBit(hA, j) != getBit(hB, j)) {
                break;
            } else {
                res += 1;
            }
        }
        ++i;
    }

    if (res > 0 && res0 == res && a[i] == 0 && b[i] == 0) { // равные строки могут быть и пустыми, и непустыми (но завершаются '\0')
        return -1;
    } else {
        return res; // "биты нумеруются, начиная с нуля", "при неполном совпадении, возвращать номер бита, следующего за последним совпадающим, то есть количество совпадающих битов"
    }
}

int main (int argc, char **argv) {
    

    return strdiff(argv[1], argv[2]);
}
