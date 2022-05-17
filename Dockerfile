FROM --platform=linux/amd64 ubuntu:20.04
RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y bmake gcc

ADD . /libfsm
WORKDIR /libfsm
RUN bmake -r
