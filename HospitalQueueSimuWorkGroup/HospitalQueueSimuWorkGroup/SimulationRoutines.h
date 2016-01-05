
float DeterminarTempoEntreChegadas(float niu)
{
	float r, X;

	r = rand() / (float)RAND_MAX;
	X = -niu * log(1 - r);
	//printf("r1 = %f  -- X1 = %f \n", r, X);
	printf("\nTempoEntreChegadas = %f \n", X);
	return X;
}


float DeterminarTempoServico(float A, float B, float T0)
{
	float r, X;

	r = rand() / (float)RAND_MAX;
	X = T0 + A + (B - A) * r;
	//printf("r2 = %f  -- X2 = %f \n", r, X);
	printf("\nTempoServico = %f \n\n", X);
	return X;
}


void Inicializacao(float Time,
	int *NumClientesSistema,
	int *EstadoSAtend1,
	int *EstadoSAtend2,
	float **FilaEventosChegadaSAtend,
	float *Clock,
	float *TempoProximaChegadaSAtend,
	float *TempoPartidaSAtend1,
	float *TempoPartidaSAtend2,
	float *TempoTotalEsperaSAtend,
	float *TempoOcupacaoSAtend1,
	float *TempoOcupacaoSAtend2,
	float *TempoTotalPermanencia,
	int *TotalClientesFilaSAtend,
	float *EstadoSTriag1,
	float *EstadoSTriag2,
	float **FilaEventosChegadaSTriag,
	float *TempoProximaChegadaSTriag,
	float *TempoPartidaSTriag1,
	float *TempoPartidaSTriag2,
	float *TempoTotalEsperaSTriag,
	float *TempoOcupacaoSTriag1,
	float *TempoOcupacaoSTriag2,
	int *TotalClientesFilaSTriag,
	float *TempoProximaChegadaSMed)
{
	*NumClientesSistema = 0;
	*EstadoSAtend1 = 0;  // livre / available
	*EstadoSAtend2 = 0;  // livre / available 
	*FilaEventosChegadaSAtend = CreateQueue();
	*Clock = 0.0;
	*TempoProximaChegadaSAtend = Time;
	*TempoPartidaSAtend1 = Infinito;
	*TempoPartidaSAtend2 = Infinito;
	*TempoTotalEsperaSAtend = 0.0;
	*TempoOcupacaoSAtend1 = 0.0;
	*TempoOcupacaoSAtend2 = 0.0;
	*TempoTotalPermanencia = 0.0;
	*TotalClientesFilaSAtend = 0;
	*EstadoSTriag1 = 0;  // livre / available
	*EstadoSTriag2 = 0;  // livre / available
	*FilaEventosChegadaSTriag = CreateQueue();
	*TempoProximaChegadaSTriag = Infinito;
	*TempoPartidaSTriag1 = Infinito;
	*TempoPartidaSTriag2 = Infinito;
	*TempoTotalEsperaSTriag = 0.0;
	*TempoOcupacaoSTriag1 = 0.0;
	*TempoOcupacaoSTriag2 = 0.0;
	*TotalClientesFilaSTriag = 0;
	*TempoProximaChegadaSMed = Infinito;
}


void GestaoTempo(float TempoProximaChegada, float TempoPartida1, float TempoPartida2, float TempoPartida3, float TempoPartida4, float TempoPartida5, float *Tempo, int *TipoEvento)
{
	*Tempo = TempoProximaChegada;
	*TipoEvento = 0;  // Chegada / Arrival
	if (TempoPartida1 < *Tempo)
	{
		*Tempo = TempoPartida1;
		*TipoEvento = 1;  // Partida1 / Departure1
	}
	if (TempoPartida2 < *Tempo)
	{
		*Tempo = TempoPartida2;
		*TipoEvento = 2;  // Partida2 / Departure2
	}
	if (TempoPartida1 < *Tempo)
	{
		*Tempo = TempoPartida1;
		*TipoEvento = 1;  // Partida1 / Departure1
	}
	if (TempoPartida2 < *Tempo)
	{
		*Tempo = TempoPartida2;
		*TipoEvento = 2;  // Partida2 / Departure2
	}
	if (TempoPartida3 < *Tempo)
	{
		*Tempo = TempoPartida3;
		*TipoEvento = 3;  // chegadaTriagem 
	}
	if (TempoPartida4 < *Tempo)
	{
		*Tempo = TempoPartida4;
		*TipoEvento = 4;  // partida triagem1 
	}
	if (TempoPartida5 < *Tempo)
	{
		*Tempo = TempoPartida5;
		*TipoEvento = 5;  // partida triagem2 
	}
	if (*Tempo == Infinito)
		*TipoEvento = -1;
}


void EventoChegada(float Tempo,
	int *NumClientesSistema,
	int *EstadoAgente1,
	int *EstadoAgente2,
	float **FilaEventosChegada,
	float *TempoProximaChegada,
	float *TempoPartida1,
	float *TempoPartida2,
	float *TempoOcupacaoAgente1,
	float *TempoOcupacaoAgente2,
	float *TempoTotalPermanencia,
	int *TotalClientesFila)
{
	float	TempoEntreChegadas,
		TempoServico;

	TempoEntreChegadas = DeterminarTempoEntreChegadas(2.0);
	*TempoProximaChegada = Tempo + TempoEntreChegadas;

	if (*EstadoAgente1 == 1)
		if (*EstadoAgente2 == 1)
		{
			*FilaEventosChegada = InsertQueue(Tempo, *FilaEventosChegada);
			*TotalClientesFila = *TotalClientesFila + 1;
		}
		else
		{
			*NumClientesSistema = *NumClientesSistema + 1;
			*EstadoAgente2 = 1;
			TempoServico = DeterminarTempoServico(0.5, 2.0, 1);
			*TempoPartida2 = Tempo + TempoServico;
			*TempoOcupacaoAgente2 = *TempoOcupacaoAgente2 + TempoServico;
			*TempoTotalPermanencia = *TempoTotalPermanencia + TempoServico;
		}
	else
	{
		*NumClientesSistema = *NumClientesSistema + 1;
		*EstadoAgente1 = 1;
		TempoServico = DeterminarTempoServico(0.5, 2.0, 1);
		*TempoPartida1 = Tempo + TempoServico;
		*TempoOcupacaoAgente1 = *TempoOcupacaoAgente1 + TempoServico;
		*TempoTotalPermanencia = *TempoTotalPermanencia + TempoServico;
	}

}
void EventoChegadaProcServ(float Tempo,
	int *NumClientesSistema,
	int *EstadoAgente1,
	int *EstadoAgente2,
	float **FilaEventosChegada,
	float *TempoProximaChegada,
	float *TempoPartida1,
	float *TempoPartida2,
	float *TempoOcupacaoAgente1,
	float *TempoOcupacaoAgente2,
	float *TempoTotalPermanencia,
	int *TotalClientesFila)
{
	float	TempoEntreChegadas,
		TempoServico;

	//TempoEntreChegadas = DeterminarTempoEntreChegadas(2.0);
	//*TempoProximaChegada = Tempo + TempoEntreChegadas;
	*TempoProximaChegada = Infinito;

	if (*EstadoAgente1 == 1)
		if (*EstadoAgente2 == 1)
		{
			*FilaEventosChegada = InsertQueue(Tempo, *FilaEventosChegada);
			*TotalClientesFila = *TotalClientesFila + 1;
		}
		else
		{
			*NumClientesSistema = *NumClientesSistema + 1;
			*EstadoAgente2 = 1;
			TempoServico = DeterminarTempoServico(0.5, 2.0, 1);
			*TempoPartida2 = Tempo + TempoServico;
			*TempoOcupacaoAgente2 = *TempoOcupacaoAgente2 + TempoServico;
			*TempoTotalPermanencia = *TempoTotalPermanencia + TempoServico;
		}
	else
	{
		*NumClientesSistema = *NumClientesSistema + 1;
		*EstadoAgente1 = 1;
		TempoServico = DeterminarTempoServico(0.5, 2.0, 1);
		*TempoPartida1 = Tempo + TempoServico;

		*TempoOcupacaoAgente1 = *TempoOcupacaoAgente1 + TempoServico;
		*TempoTotalPermanencia = *TempoTotalPermanencia + TempoServico;
	}

}



void EventoPartida(float Tempo,
	int *NumClientesSistema,
	int *EstadoAgente,
	float **FilaEventosChegada,
	float *TempoPartida,
	float *tempoProServ,
	float *TempoOcupacaoAgente,
	float *TempoTotalEspera,
	float *TempoTotalPermanencia)
{
	float	TempoChegadaCliente,
		TempoEsperaCliente,
		TempoServico;

	if (EmptyQueue(*FilaEventosChegada))
	{
		*EstadoAgente = 0;
		*tempoProServ = *TempoPartida;
		*TempoPartida = Infinito;
	}
	else
	{
		TempoChegadaCliente = Front(*FilaEventosChegada);
		*FilaEventosChegada = RemoveQueue(*FilaEventosChegada);
		TempoEsperaCliente = Tempo - TempoChegadaCliente;
		*NumClientesSistema = *NumClientesSistema + 1;
		TempoServico = DeterminarTempoServico(0.5, 2.0, 1);
		*tempoProServ = *TempoPartida;
		*TempoPartida = Tempo + TempoServico;		
		*TempoTotalEspera = *TempoTotalEspera + TempoEsperaCliente;
		*TempoOcupacaoAgente = *TempoOcupacaoAgente + TempoServico;
		*TempoTotalPermanencia = *TempoTotalPermanencia + TempoServico + TempoEsperaCliente;
	}
}

void ContadoresEstatisticos(int NumClientesSistema,
	int TotalClientesFila,
	float TempoOcupacaoAgente1,
	float TempoOcupacaoAgente2,
	float TempoTotalEspera,
	float TempoTotalPermanencia,
	float TempoTotalSistema)
{
	int TaxaOcupacaoAgentes,
		TaxaOcupacaoAgente1,
		TaxaOcupacaoAgente2;
	float	NumMedioClientesFila,
		TempoMedioEsperaClientes,
		TempoMedioPermanenciaClientes;

	TaxaOcupacaoAgentes = (TempoOcupacaoAgente1 + TempoOcupacaoAgente2) / (2 * TempoTotalSistema) * 100;
	TaxaOcupacaoAgente1 = TempoOcupacaoAgente1 / TempoTotalSistema * 100;
	TaxaOcupacaoAgente2 = TempoOcupacaoAgente2 / TempoTotalSistema * 100;
	NumMedioClientesFila = TotalClientesFila / (float)NumClientesSistema;
	TempoMedioEsperaClientes = TempoTotalEspera / NumClientesSistema;
	TempoMedioPermanenciaClientes = TempoTotalPermanencia / NumClientesSistema;

	printf("TaxaOcupacaoAgentes = %d%%\n", TaxaOcupacaoAgentes);
	printf("TaxaOcupacaoAgente1 = %d%%\n", TaxaOcupacaoAgente1);
	printf("TaxaOcupacaoAgente2 = %d%%\n", TaxaOcupacaoAgente2);
	printf("NumMedioClientesFila = %.3f\n", NumMedioClientesFila);
	printf("TempoMedioEsperaClientes = %.3f\n", TempoMedioEsperaClientes);
	printf("TempoMedioPermanaenciaClientes = %.3f\n", TempoMedioPermanenciaClientes);
}