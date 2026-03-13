FROM ubuntu:24.04

RUN apt-get update && apt-get install -y g++ make libgtest-dev cpplint clang-format

WORKDIR /app
COPY . .

ENTRYPOINT ["make"]