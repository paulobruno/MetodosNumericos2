# 2014, Fortaleza, Ceara
#
# UNIVERSIDADE FEDERAL DO CEARA
# CURSO DE COMPUTACAO
# METODOS NUMERICOS II
# PROFESSORA: Emanuele Marques dos Santos
#
# Paulo Bruno de Sousa Serafim    354086

CC		= g++
CFLAGS	= -c -g

EXECALL	        = execAll
EXECTRIDIAGONAL = execTridiagonal
EXECGAUSSIAN    = execGaussianElimination
EXECGAUSSSEIDEL = execGaussSeidel

LINEAR		= LinearSystem.cpp
TRIDIAGONAL = TridiagonalMatrix.cpp
GAUSSIAN	= GaussianElimination.cpp
GAUSSSEIDEL = GaussSeidel.cpp

METHODS	= \
	$(LINEAR) \
	$(TRIDIAGONAL) \
	$(GAUSSIAN) \
	$(GAUSSSEIDEL)

RM		= rm -rf

%.o: %.cpp
	$(CC) $(CFLAGS) $<


# Executaveis

$(EXECALL): \
	$(EXECTRIDIAGONAL) \
	$(EXECGAUSSIAN) \
	$(EXECGAUSSSEIDEL)

$(EXECTRIDIAGONAL): $(LINEAR:.cpp = .o) $(TRIDIAGONAL:.cpp = .o) main_tridiagonalMatrix.o
	$(CC) $^ -o $@

$(EXECGAUSSIAN): $(LINEAR:.cpp = .o) $(GAUSSIAN:.cpp = .o) main_gaussianElimination.o
	$(CC) $^ -o $@

$(EXECGAUSSSEIDEL): $(LINEAR:.cpp = .o) $(GAUSSSEIDEL:.cpp = .o) main_gaussSeidel.o
	$(CC) $^ -o $@


# make's individuais

all: $(EXECALL)

tridiagonal: $(EXECTRIDIAGONAL)

gaussian: $(EXECGAUSSIAN)

gaussseidel: $(EXECGAUSSSEIDEL)


# outra opcoes

.PHONY: clean cleanall

clean:
	$(RM) *.o *~

cleanall:
	$(RM) $(EXECTRIDIAGONAL) $(EXECGAUSSIAN) $(EXECGAUSSSEIDEL) *.o *~

help:
	@echo "# "
	@echo "# ----- MAKE HELP -----"
	@echo "# "
	@echo "#     make           : Compila todos os arquivos e gera varios executaveis."
	@echo "#     make all       : O mesmo que make."
	@echo "# "
	@echo "#     make trapezium : Compila somente os arquivos que utilizam matriz tridiagonal."
	@echo "#                        Gera executavel execTridiagonal."
	@echo "#     make simpson13 : Compila somente os arquivos que utilizam eliminacao de Gauss."
	@echo "#                        Gera executavel execGaussianElimination."
	@echo "#     make simpson38 : Compila somente os arquivos que utilizam Gauss-Seidel."
	@echo "#                        Gera executavel execGaussSeidel."
	@echo "#     make clean     : Elimina os arquivos criados no processo de compilacao."
	@echo "#     make cleanall  : O mesmo que make clean e elimina tambem os executaveis."
	@echo "#     make help      : Mostra esta ajuda."
	@echo "# "
	@echo "#     Para mais informacoes consulte o arquivo README."
	@echo "# "
