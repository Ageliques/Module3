# Module3
1.c 
Написать программу, вычисляющую площади квадратов с заданной длиной стороны.
Длины сторон передаются как аргументы запуска.
Расчеты делают родительский и дочернийbпроцессы, разделяя задачи примерно поровну.

2.c
Написать программу, похожую на командный интерпретатор.
При запуске выводится приглашение, и пользователь вводит имя и аргументы программы, которую желает запустить.
Программы для запуска написать самостоятельно и поместить в тот же каталог (реализованы 2 программы sum.c (сумма) и max.c (максимальное число)).

3.с
Скорректировать решение задачи о книге контактов из модуля 2 так, чтобы список контактов хранился в файле.
Использовать небуферизованный ввод-вывод.
При запуске программы список считывается из файла, при завершении программы список записывается в файл.
Учесть, что при запуске программы может не быть сохраненных данных.

4.с
Написать программу, порождающую дочерний процесс и использующую однонаправленный обмен данными.
Процесс-потомок генерирует случайные числа и отправляет родителю.
Родитель выводит числа на экран и в файл.
Количество чисел задается в параметрах запуска приложения.

5.с
изменить программу 4 так, чтобы родительский процесс генерировал новые числа в файл, дочерний процесс выводил информацию из файла
Если родительский процесс собирается изменить файл, то он отправляет сигнал SIGUSR1 (блокировка доступа к файлу).
Когда родительский процесс завершил модификацию файла, он отправляет сигнал SIGUSR2 (разрешение доступа к файлу).
Дочерний процесс отправляет новое число родительскому после того, как прочитал файл.
