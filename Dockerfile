FROM --platform=linux/amd64 ubuntu:20.04 as builder
RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y bmake gcc

ADD . /libfsm
WORKDIR /libfsm
RUN bmake -r

RUN mkdir -p /deps
RUN ldd /libfsm/build/bin/fsm | tr -s '[:blank:]' '\n' | grep '^/' | xargs -I % sh -c 'cp % /deps;'

FROM ubuntu:20.04 as package

COPY --from=builder /deps /deps
COPY --from=builder /libfsm/build/bin/fsm /libfsm/build/bin/fsm
ENV LD_LIBRARY_PATH=/deps
