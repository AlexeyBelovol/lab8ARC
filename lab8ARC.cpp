#include <iostream>

int main() {
    int array[10] = { 3, -1, 4, -5, -6, 7, -8, 9, -2, 10 }; // Масив з 10 елементів
    int negativeCount = 0; // Змінна для збереження кількості від’ємних елементів

    _asm {
        xor ESI, ESI; Обнулити ESI для підрахунку від’ємних елементів
        lea EBX, array; Завантажити адресу масиву в EBX
        mov ECX, 10; Встановити лічильник на 10 (кількість елементів)

        check_loop:
        mov EAX, dword ptr[EBX]; Завантажити поточний елемент масиву в EAX
            cmp EAX, 0; Порівняти з 0
            jl increment_count; Якщо менше нуля, збільшити лічильник

            next_element :
        add EBX, 4; Перейти до наступного елемента масиву
            loop check_loop; Повторити цикл для наступного елемента
            jmp end; Перейти до кінця, коли всі елементи перевірено

            increment_count :
        inc ESI; Збільшити лічильник від’ємних елементів
            jmp next_element; Перейти до наступного елемента

            end :
        mov negativeCount, ESI; Зберегти кількість від’ємних елементів у negativeCount
    }

    std::cout << "Number of negative elements: " << negativeCount << std::endl;

    return 0;
}
