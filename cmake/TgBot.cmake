# cmake/TgBot.cmake

# Проверка, была ли передана переменная BASE_PATH
if(NOT BASE_PATH)
    message(STATUS "BASE_PATH is not defined. Using default value.")
    set(BASE_PATH "/usr/local")  # Указываем путь по умолчанию /usr/local/include 
    
else()
    message(STATUS "Using BASE_PATH: ${BASE_PATH}")
    set(TgBot_DIR "${BASE_PATH}/lib/cmake/TgBot/")

endif()

set(TgBot_include_DIR "${BASE_PATH}/include/")
set(TgBot_LIBRARIES "${BASE_PATH}/lib")

find_package(TgBot REQUIRED)

set(TGBOT_BASE_PATH ${BASE_PATH} CACHE PATH "Base path for the TgBot project")
set(TgBot_INCLUDE_DIR ${TgBot_include_DIR} CACHE PATH "Include directory for TgBot")
set(TgBot_LIB_DIR ${TgBot_LIBRARIES} CACHE PATH "Library directory for TgBot")