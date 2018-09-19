FROM gcc
RUN wget https://repo.continuum.io/miniconda/Miniconda3-latest-Linux-x86_64.sh -P /tmp
RUN chmod +x /tmp/Miniconda3-latest-Linux-x86_64.sh
RUN /tmp/Miniconda3-latest-Linux-x86_64.sh -p /opt/conda -b
ENV PATH="/opt/conda/bin:${PATH}"
COPY env.yml /tmp/env.yml
RUN conda env update -f=/tmp/env.yml -n base
RUN useradd -d jovyan
USER jovyan
CMD ["/bin/bash"]
