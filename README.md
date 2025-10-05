# Сборка проекта
## Сборка llvm
1. Создать рабочую директория
```sh
mkdir topt-workdir
cd topt-workdir
```
2. Клонировать проект учебного компилятора topt
```sh
git clone git@github.com:ikulagin/train-opt.git
```
3. Клонирвоать проект llvm-project и переходим на ветку `top-main`
```sh
git clone git@github.com:compiler-courses/llvm-project.git
cd llvm-project
git switch top-main
cd ..
```
4. Копировать шаблон cmake-preset в директорию `llvm-project/llvm/`
```sh
cp train-opt/presets/llvm/CMakePresets.json llvm-project/llvm/
```
5. Сконфигурировать cmake-сборку llvm и заупстить его сборку
```sh
cd llvm-project/llvm
# Конфигурирование debug-сборки
cmake --preset debug
# Запуск сборки
cmake --build --preset debug
cd ../..
```
6. Сконфигурировать cmake-сборку topt и заупстить его сборку
```sh
cd train-opt
# Конфигурирование debug-сборки
cmake --preset debug
# Запуск сборки
cmake --build --preset debug
```
