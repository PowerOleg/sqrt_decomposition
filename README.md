### SQRT decomposition
//разобраная задача  поиска минимального элемента между индексом 1 включительно и индексом 7 не включительно

Разбиваем на блоки, размер блока корень из размера массива. В препроцессинге заполняем массив с блоками который для блока хранит минимальное значение .Определяем номер блока слева, который внутри диапазона т.е. покрыт диапазоном, далее определяем номер блока справа который также внутри полностью диапазона. Пробегаемся и сравниваем значения от левого индекса до начала левого блока, потом сравниваем блоки, далее от конца правого блока до индекса правее блока, это индекс который делит слеждующий блок. И получаем в итоге минимальное значение полученое с использованием SQRT декомпозиции
