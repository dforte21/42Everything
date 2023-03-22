FROM  alpine:3.15.0

RUN apk update; \
    apk add --update nodejs npm

COPY ./tools /

CMD ["node", "run.js"]