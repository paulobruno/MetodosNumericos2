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
EXECPOWER       = execPowerIteration
EXECINVERSE     = execInverseIteration
EXECSHIFT       = execShiftIteration
EXECJACOBI      = execJacobi
EXECQRALGORITHM = execQrAlgorithm
EXECHOUSEHOLDER = execHouseholderTransformation

EIGENVALUE       = Eigenvalue.cpp
POWERITERATION   = PowerIteration.cpp 
INVERSEITERATION = InverseIteration.cpp
SHIFTITERATION   = ShiftIteration.cpp
JACOBI			 = Jacobi.cpp
QRALGORITHM      = QrAlgorithm.cpp
HOUSEHOLDER      = HouseholderTransformation.cpp

METHODS	= \
	$(EIGENVALUE) \
	$(POWERITERATION) \
	$(INVERSEITERATION) \
	$(SHIFTITERATION) \
	$(JACOBI) \
	$(QRALGORITHM) \
	$(HOUSEHOLDER)

RM		= rm -rf

%.o: %.cpp
	$(CC) $(CFLAGS) $<


# Executaveis

$(EXECALL): \
	$(EXECPOWER) \
	$(EXECINVERSE) \
	$(EXECSHIFT) \
	$(EXECJACOBI) \
	$(EXECQRALGORITHM) \
	$(EXECHOUSEHOLDER)
	
$(EXECPOWER): $(POWERITERATION:.cpp = .o) $(EIGENVALUE:.cpp = .o) main_powerIteration.cpp
	$(CC) $^ -o $@
	
$(EXECINVERSE): $(INVERSEITERATION:.cpp = .o) $(POWERITERATION:.cpp = .o) $(EIGENVALUE:.cpp = .o) main_inverseIteration.cpp
	$(CC) $^ -o $@
	
$(EXECSHIFT): $(SHIFTITERATION:.cpp = .o) $(POWERITERATION:.cpp = .o) $(EIGENVALUE:.cpp = .o) main_shiftIteration.cpp
	$(CC) $^ -o $@
	
$(EXECJACOBI): $(JACOBI:.cpp = .o) $(EIGENVALUE:.cpp = .o) main_jacobi.cpp
	$(CC) $^ -o $@
	
$(EXECQRALGORITHM): $(QRALGORITHM:.cpp = .o) $(EIGENVALUE:.cpp = .o) main_qrAlgorithm.cpp
	$(CC) $^ -o $@
	
$(EXECHOUSEHOLDER): $(HOUSEHOLDER:.cpp = .o) $(EIGENVALUE:.cpp = .o) main_householderTransformation.cpp
	$(CC) $^ -o $@
	
	
# make's individuais

all: $(EXECALL)

powerIteration: $(EXECPOWER)

inverseIteration: $(EXECINVERSE)

shiftInteration: $(EXECSHIFT)

jacobi: $(EXECJACOBI)

qrAlgorithm: $(EXECQRALGORITHM)

householder: $(EXECHOUSEHOLDER)


# outra opcoes

.PHONY: clean cleanall

clean:
	$(RM) *.o *~

cleanall:
	$(RM) $(EXECPOWER) $(EXECINVERSE) $(EXECSHIFT) $(EXECJACOBI) $(EXECQRALGORITHM) $(EXECHOUSEHOLDER) *.o *~

help:
	@echo "# "
	@echo "# ----- MAKE HELP -----"
	@echo "# "
	@echo "#     make     : Compila todos os arquivos e gera varios executaveis."
	@echo "#     make all : O mesmo que make."
	@echo "# "
	@echo "#     make powerIteration   : Compila os arquivos do metodo da potencia."
	@echo "#                               Gera executavel execPowerIteration."
	@echo "#     make inverseIteration : Compila os arquivos do metodo da potencia inversa."
	@echo "#                               Gera executavel execInverseIteration."
	@echo "#     make shiftInteration  : Compila os arquivos do metodo da potencia deslocada."
	@echo "#                               Gera executavel execShiftIteration."
	@echo "#     make jacobi           : Compila os arquivos do metodo de Jacobi."
	@echo "#                               Gera executavel execJacobi."
	@echo "#     make qrAlgorithm      : Compila os arquivos do metodo QR."
	@echo "#                               Gera executavel execQrAlgorithm."
	@echo "#     make householder      : Compila os arquivos do metodo de householder."
	@echo "#                               Gera executavel execHouseholderTransformation."
	@echo "#     make clean     : Elimina os arquivos criados no processo de compilacao."
	@echo "#     make cleanall  : O mesmo que make clean e elimina tambem os executaveis."
	@echo "#     make help      : Mostra esta ajuda."
	@echo "# "
	@echo "#     Para mais informacoes consulte o arquivo README."
	@echo "# "
