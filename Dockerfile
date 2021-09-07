FROM alpine
RUN apk add --no-cache build-base g++ make
WORKDIR /src
COPY . .
RUN cd src/ && make
CMD ["src/calculator"]