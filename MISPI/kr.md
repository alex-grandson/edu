# Контрольная работа 1:

### Каскадная модель
стр. 12

У. Ройс

Требования - Разработка - Тестирование - Разработка - Тестирование - Раз...

Минусы:
- Поздняя обратная связь
### Методология Ройса. Что крутого предложил
стр. 13
- Предварительный дизайн (во избежание поздней обратной связи)
- Подключение пользователя
- Документирование
- Тестирование

### Git rebase
[Дока](https://git-scm.com/book/ru/v2/%D0%92%D0%B5%D1%82%D0%B2%D0%BB%D0%B5%D0%BD%D0%B8%D0%B5-%D0%B2-Git-%D0%9F%D0%B5%D1%80%D0%B5%D0%B1%D0%B0%D0%B7%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D0%B5)

### Типы рисков
стр. 58
- Прямые и косвенные
- Ресурсные
- Бизнес-риски
- Технические 
- Политические
- Форс-мажор

### Свойства требований
стр. 43
- Корректность
- Однозначность
- Полнота
- Непротиворечивость
- Приоритизация
- Модифицируемость
- Отслеживаемость

### Атрибуты требований
стр. 51
- Приоритет (must / should / could have)
- Статус (Предложенные / одобренные / отклоненные / включенные)
- Трудоемкость (в человеко-часах)
- Риск
- Стабильность (Высокая / средняя / низкая)
- Целевая версия
### Что такое `svn serve`
`svnserve` - Server for the 'svn' repository access method

[Link](https://www.opennet.ru/man.shtml?topic=svnserve&category=8&russian=2)
### FURPS+
стр. 45

- `F`unctional - Функциональный требования - Что система _должна_ делать
- Non-functional - Как система должна это делать:
    - `U`sability - тр. к пользовательским характеристикам - GUI
    - `R`eliability - тр. к надежности - требуемая готовность выполнения операций
    - `P`erformance - тр. к производительности - способность обеспечить заданное время отклика или скорость операций
    - `S`upportability - тр. к условиям поддержки - способность обновление ПО без остановки функционала (кластерные технологии)
    
### Спиральная модель
стр. 17

Б. Боем

- Каждый виток спирали = одна фаза разработки --> построение прототипа
1. Постановка целей
2. Альтернативные решения и ограничения
3. Анализ рисков
4. Разработка и валидация ПО

Main feature: Включил изменения как часть процесса разработки. 
Определил, что их можно принять, отклонить, игнорировать в зависимости от риска.

### Пример команды SVN - пояснить

# Контрольная работа 2:

### Что такое GAV
Нейминг конвенция в основном для плагинов Maven: `groupId:artefact:version`

### Прописать структуру подключения Junit через зависимость Maven/Gradle на выбор
По конвенции GAV:
```xml
<dependency>
    <groupId>junit</groupId>
    <artifactId>junit</artifactId>
    <version>4.13.2</version>
</dependency>
```

### Как залить на удаленный реп свой изменения используя git flow

### Что такое autoscan

### Что такое autoheader

### Способы параллельной модификации файлов
стр. 72

Lock-modify-unlock
- Невозможно редактировать одновременно
- В основном на VCS на файловой системе

Copy-modify-merge
- Своя рабочая копия у каждого разработчика
- Можно одновременно, но потом все равно мержить

