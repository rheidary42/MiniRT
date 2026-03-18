FROM --platform=linux/amd64 debian:bullseye-slim

# Install build tools and X11 dependencies for MiniLibX
RUN apt-get update && apt-get install -y \
    build-essential \
    gcc \
    gdb \
    lldb \
    git \
    pkg-config \
    libx11-dev \
    libxext-dev \
    libbsd-dev \
    x11-apps \
    make \
    && rm -rf /var/lib/apt/lists/*

RUN echo 'export PS1="\W> "' >> ~/.bashrc