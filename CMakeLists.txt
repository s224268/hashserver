cmake_minimum_required(VERSION 3.25)
project(hashserver)

# Find OpenSSL
find_package(OpenSSL REQUIRED)

# Add your source files
add_executable(hashserver server.c)

# Link OpenSSL libraries to your project
target_link_libraries(hashserver PRIVATE OpenSSL::SSL OpenSSL::Crypto)