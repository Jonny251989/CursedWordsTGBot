# cmake/TgBot.cmake

# Проверка, была ли передана переменная BASE_PATH
if(NOT TGBOT_CPP_INSTALL_PFEFIX)
    message(STATUS "TGBOT_CPP_INSTALL_PFEFIX is not defined. Using default value.")
    set(TGBOT_CPP_INSTALL_PFEFIX "/usr/local")  # Указываем путь по умолчанию /usr/local/include 
    
else()
    message(STATUS "Using TGBOT_CPP_INSTALL_PFEFIX: ${TGBOT_CPP_INSTALL_PFEFIX}")
    set(TgBot_DIR "${TGBOT_CPP_INSTALL_PFEFIX}/lib/cmake/TgBot/")

endif()

set(TgBot_include_DIR "${TGBOT_CPP_INSTALL_PFEFIX}/include/")
set(TgBot_LIBRARIES "${TGBOT_CPP_INSTALL_PFEFIX}/lib")

find_package(TgBot REQUIRED)

set(TGBOT_CPP_INSTALL_PFEFIX ${TGBOT_CPP_INSTALL_PFEFIX} CACHE PATH "Base path for the TgBot project")
set(TgBot_INCLUDE_DIR ${TgBot_include_DIR} CACHE PATH "Include directory for TgBot")
set(TgBot_LIB_DIR ${TgBot_LIBRARIES} CACHE PATH "Library directory for TgBot")