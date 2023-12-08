SOURCES=ex.cpp utilizator.cpp operator.cpp criptareandvalidare.cpp ruta.cpp

ex: $(SOURCES)
	g++ -o ex $(SOURCES)


