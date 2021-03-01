FROM ubuntu:20.04

ENV DEBIAN_FRONTEND noninteractive

RUN apt update && apt -y install build-essential cmake git curl unzip tar zip pkg-config

ARG USERNAME=dev
ARG USER_UID=1000
ARG USER_GID=$USER_UID

RUN apt install sudo -y


RUN adduser ${USERNAME} --gecos "" --disabled-password
RUN echo ${USERNAME} ALL=\(ALL\) NOPASSWD:ALL > /etc/sudoers.d/${USERNAME} &&\
    chmod 0440 /etc/sudoers.d/${USERNAME}


ENV VCPKGROOT="/home/${USERNAME}/vcpkg"
ENV PATH="${VCPKGROOT}:${PATH}"

# Install VCPKG
RUN git clone https://github.com/microsoft/vcpkg $VCPKGROOT &&\
    $VCPKGROOT/bootstrap-vcpkg.sh

RUN vcpkg install sdl2 sdl2-image
RUN chown -R ${USERNAME} ${VCPKGROOT}

USER ${USERNAME}

# Install needed libraries
WORKDIR /app
RUN sudo chown -R ${USERNAME} .
COPY --chown=dev ./src/ ./src
COPY --chown=dev CMakeLists.txt .

# # Build Project
RUN if ! [ -d "build" ]; then mkdir build; fi &&\
    cd build &&\
    cmake .. -DCMAKE_TOOLCHAIN_FILE=${VCPKGROOT}/scripts/buildsystems/vcpkg.cmake &&\
    make

# ENV BUILDLOCATION=${BUILDLOCATION}
WORKDIR /app/build
CMD ["bash", "-c","make && cp AlienInvasion ../artifacts"]
