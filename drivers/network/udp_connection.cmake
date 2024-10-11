set(DRIVER_NAME udp_connection) # 변수 설정

if (NOT TARGET ${DRIVER_NAME}) # 드라이버가 컴파일 안되었을 경우
    add_library(${DRIVER_NAME} INTERFACE) # 드라이버 컴파일
endif()

target_sources(${DRIVER_NAME} INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/udp_connection.hpp
)

target_include_directories(${DRIVER_NAME} INTERFACE ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(${DRIVER_NAME} INTERFACE
    pico_cyw43_arch_threadsafe_background
    
)