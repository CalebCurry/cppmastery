#base image
FROM gcc:latest

#set working dir
WORKDIR /usr/src/app

#copy some files
COPY . .

RUN g++ intro.cpp -o myapp

CMD ["./myapp"]