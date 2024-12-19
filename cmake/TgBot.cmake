# cmake/TgBot.cmake

# Проверка, была ли передана переменная BASE_PATH
if(NOT BASE_PATH)
    message(STATUS "BASE_PATH is not defined. Using default value.")
    set(BASE_PATH "/usr/local")  # Указываем путь по умолчанию /usr/local/include 
    #set(TgBot_DIR "${BASE_PATH}/lib/cmake/TgBot/")
    set(TgBot_include_DIR "${BASE_PATH}/include/")
    set(TgBot_LIBRARIES "${BASE_PATH}/lib")

else()
    message(STATUS "Using BASE_PATH: ${BASE_PATH}")
    set(TgBot_DIR "${BASE_PATH}/lib/cmake/TgBot/")
    set(TgBot_include_DIR "${BASE_PATH}/include/")
    set(TgBot_LIBRARIES "${BASE_PATH}/lib")
endif()

# Настройка путей к библиотекам и заголовочным файлам TgBot

# Настройка поиска библиотеки TgBot
# Это позволит использовать find_package(TgBot) в других частях проекта
find_package(TgBot REQUIRED)

# Экспортируем переменные для использования в других частях проекта
set(TGBOT_BASE_PATH ${BASE_PATH} CACHE PATH "Base path for the TgBot project")
set(TgBot_INCLUDE_DIR ${TgBot_include_DIR} CACHE PATH "Include directory for TgBot")
set(TgBot_LIB_DIR ${TgBot_LIBRARIES} CACHE PATH "Library directory for TgBot")