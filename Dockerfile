# Ubuntu 22.04 LTS를 베이스 이미지로 사용
FROM ubuntu:22.04

# 패키지 설치 시 대화형 프롬프트를 비활성화
ARG DEBIAN_FRONTEND=noninteractive

# 패키지 목록 업데이트 및 기본 패키지 설치
RUN apt-get update && \
    apt-get install -y curl vim g++ && \
    rm -rf /var/lib/apt/lists/*

# 기본 사용자 추가 및 설정
RUN useradd -ms /bin/bash jhyunwoo
USER jhyunwoo

# 기본 작업 디렉토리 설정
WORKDIR /home/jhyunwoo