# Use GCC current version
FROM gcc:5.4

# Copy files defined to Dockerfile
COPY . /usr/src/Dockerfile

# Setting the work directory
WORKDIR /usr/src/Dockerfile

# Compiling using GCC
RUN gcc arquivo_trava.c -o arquivo_trava

# Executing on Docker using terminal
CMD ["./arquivo_trava"]

