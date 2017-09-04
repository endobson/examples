FROM debian:11
COPY main.sh make-req ./
ENTRYPOINT ["./main.sh"]
