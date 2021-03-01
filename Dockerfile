FROM ubuntu:20.04

ENV DEBIAN_FRONTEND noninteractive

RUN apt update && apt -y install build-essential cmake git curl unzip tar zip pkg-config

ARG USERNAME=dev
ARG USER_UID=1000
ARG USER_GID=$USER_UID
# ARG BUILDLOCATION=build-container

RUN apt install sudo -y

# RUN groupadd --gid ${USER_GID} ${USERNAME} &&\
#     useradd --uid ${USER_UID} --gid ${USER_GID} -m ${USERNAME} &&\
#     echo ${USERNAME} ALL=\(ALL\) NOPASSWD:ALL > /etc/sudoers.d/${USERNAME} &&\
#     chmod 0440 /etc/sudoers.d/${USERNAME}

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
# RUN rm -rf build/ &&\
RUN if ! [ -d "build" ]; then mkdir build; fi &&\
    cd build &&\
    cmake .. -DCMAKE_TOOLCHAIN_FILE=${VCPKGROOT}/scripts/buildsystems/vcpkg.cmake &&\
    make

# ENV BUILDLOCATION=${BUILDLOCATION}
WORKDIR /app/build
CMD ["bash", "-c","make && cp AlienInvasion ../artifacts"]

# # Build Project
# RUN rm -rf ${BUILDLOCATION}/ &&\
#     mkdir ${BUILDLOCATION} &&\
#     cd ${BUILDLOCATION} &&\
#     cmake .. -DCMAKE_TOOLCHAIN_FILE=${VCPKGROOT}/scripts/buildsystems/vcpkg.cmake &&\
#     make

# ENV BUILDLOCATION=${BUILDLOCATION}
# CMD ["bash", "-c", "cd ${BUILDLOCATION} && make"]
# CMD ["bash", "-c", "cd ${BUILDLOCATION} && pwd && ls && make"]


# COPY --chown=dev . .
# # RUN ./configure.sh
# RUN sudo chown -R ${USERNAME} .

# CMD ["bash", "-c", "make && ./run.sh"]

# RUN git clone https://github.com/Microsoft/vcpkg.git /opt/vcpkg

# WORKDIR /opt/vcpkg

# RUN ./bootstrap-vcpkg.sh &&\
#     ./vcpkg integrate install &&\ 
#     ./vcpkg integrate bash &&\ 
#     echo 'export PATH=$PATH:/opt/vcpkg' >>~/.bashrc

# RUN ./vcpkg install sdl2
# RUN ./vcpkg install sdl2-image

# ARG USERNAME=dev
# ARG USER_UID=1000
# ARG USER_GID=$USER_UID

# RUN apt install sudo -y

# RUN groupadd --gid ${USER_GID} ${USERNAME} &&\
#     useradd --uid ${USER_UID} --gid ${USER_GID} -m ${USERNAME} &&\
#     echo ${USERNAME} ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/${USERNAME} &&\
#     chmod 0440 /etc/sudoers.d/${USERNAME}

# USER ${USERNAME}
# RUN sudo chown -R ${USERNAME} /opt/vcpkg

# WORKDIR /app


# # COMPILE IF THERE ARE CHANGES AND RUN APPLICATION
# CMD ["bash", "-c", "make -j$(nproc) && ./AlienInvasion"]