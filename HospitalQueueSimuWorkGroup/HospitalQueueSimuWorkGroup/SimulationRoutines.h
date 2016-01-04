
float DeterminarTempoEntreChegadas(float niu)
{
	float r, X;

	r = rand() / (float)RAND_MAX;
	X = -niu * log(1 - r);
	//printf("r1 = %f  -- X1 = %f \n", r, X);
	printf("\nTempoProxChegada = %f \n", r, X);

	return X;
}


float DeterminarTempoServico(float A, float B, float T0)
{
	float r, X;

	r = rand() / (float)RAND_MAX;
	X = T0 + A + (B - A) * r;
	//printf("r2 = %f  -- X2 = %f \n", r, X);
	printf("TempoServico = %f \n\n", r, X);
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
	int *TotalClientesFilaSTriag)
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
}


void GestaoTempo(float TempoProximaChegadaSAtend,
	float TempoPartidaSAtend1,
	float TempoPartidaSAtend2,
	float TempoProximaChegadaSTriag,
	float TempoPartidaSTriag1,
	float TempoPartidaSTriag2,
	float *Tempo,
	int *TipoEvento)
{
	//if (TempoProximaChegadaSAtend < TempoProximaChegadaSTriag)
	//{
	*Tempo = TempoProximaChegadaSAtend;
	*TipoEvento = 0;  // Chegada / Arrival
					  //}		
					  //else
					  //{
					  //	*Tempo = TempoProximaChegadaSTriag;
					  //	*TipoEvento = 3;  // Chegada / Arrival
					  //}	

	if (TempoPartidaSAtend1 < *Tempo)
	{
		*Tempo = TempoPartidaSAtend1;
		*TipoEvento = 1;  // Partida1 / Departure1
	}
	if (TempoPartidaSAtend2 < *Tempo)
	{
		*Tempo = TempoPartidaSAtend2;
		*TipoEvento = 2;  // Partida2 / Departure2
	}
	if (TempoProximaChegadaSTriag < *Tempo)
	{
		*Tempo = TempoProximaChegadaSTriag;
		*TipoEvento = 3;  // Partida1 / Departure1
	}
	if (TempoPartidaSTriag1 < *Tempo)
	{
		*Tempo = TempoPartidaSTriag1;
		*TipoEvento = 4;  // Partida1 / Departure1
	}
	if (TempoPartidaSTriag2 < *Tempo)
	{
		*Tempo = TempoPartidaSTriag2;
		*TipoEvento = 5;  // Partida2 / Departure2
	}
	if (*Tempo == Infinito)
		*TipoEvento = -1;
}

void EventoChegada(float Tempo,
	int *NumClientesSistema,
	int *EstadoSAtend1,
	int *EstadoSAtend2,
	float **FilaEventosChegadaSAtend,
	float *TempoProximaChegadaSAtend,
	float *TempoPartidaSAtend1,
	float *TempoPartidaSAtend2,
	float *TempoProximaChegadaSTriag,
	float *TempoOcupacaoSAtend1,
	float *TempoOcupacaoSAtend2,
	float *TempoTotalPermanencia,
	int *TotalClientesFilaSAtend)
{
	float	TempoEntreChegadas,
		TempoServico;

	TempoEntreChegadas = DeterminarTempoEntreChegadas(2.0);
	*TempoProximaChegadaSAtend = Tempo + TempoEntreChegadas;

	if (*EstadoSAtend1 == 1)
		if (*EstadoSAtend2 == 1)
		{
			*FilaEventosChegadaSAtend = InsertQueue(Tempo, *FilaEventosChegadaSAtend);
			*TotalClientesFilaSAtend = *TotalClientesFilaSAtend + 1;
		}
		else
		{
			*NumClientesSistema = *NumClientesSistema + 1;
			*EstadoSAtend2 = 1;
			TempoServico = DeterminarTempoServico(0.5, 2.0, 1);
			*TempoPartidaSAtend2 = Tempo + TempoServico;
			//*TempoProximaChegadaSTriag = Tempo + TempoServico;
			*TempoOcupacaoSAtend2 = *TempoOcupacaoSAtend2 + TempoServico;
			*TempoTotalPermanencia = *TempoTotalPermanencia + TempoServico;
		}
	else
	{
		*NumClientesSistema = *NumClientesSistema + 1;
		*EstadoSAtend1 = 1;
		TempoServico = DeterminarTempoServico(0.5, 2.0, 1);
		*TempoPartidaSAtend1 = Tempo + TempoServico;
		//*TempoProximaChegadaSTriag = Tempo + TempoServico;
		*TempoOcupacaoSAtend1 = *TempoOcupacaoSAtend1 + TempoServico;
		*TempoTotalPermanencia = *TempoTotalPermanencia + TempoServico;
	}

}

void EventoChegadaSTriag(float Tempo,
	int *EstadoSTriag1,
	int *EstadoSTriag2,
	float **FilaEventosChegadaSTriag,
	float *TempoProximaChegadaSTriag,
	float *TempoPartidaSTriag1,
	float *TempoPartidaSTriag2,
	float *TempoOcupacaoSTriag1,
	float *TempoOcupacaoSTriag2,
	float *TempoTotalPermanencia,
	int *TotalClientesFilaSTriag)
{
	float	TempoEntreChegadas,
		TempoServico;

	//TempoEntreChegadas = DeterminarTempoEntreChegadas(2.0);
	//*TempoProximaChegadaSTriag = Tempo + TempoEntreChegadas;

	if (*EstadoSTriag1 == 1)
		if (*EstadoSTriag2 == 1)
		{
			*FilaEventosChegadaSTriag = InsertQueue(Tempo, *FilaEventosChegadaSTriag);
			*TotalClientesFilaSTriag = *TotalClientesFilaSTriag + 1;
		}
		else
		{
			*EstadoSTriag2 = 1;
			TempoServico = DeterminarTempoServico(0.5, 2.0, 1);
			*TempoPartidaSTriag2 = Tempo + TempoServico;
			//*TempoProximaChegadaSTriag = Tempo + TempoServico;
			*TempoOcupacaoSTriag2 = *TempoOcupacaoSTriag2 + TempoServico;
			*TempoTotalPermanencia = *TempoTotalPermanencia + TempoServico;
		}
	else
	{
		*EstadoSTriag1 = 1;
		TempoServico = DeterminarTempoServico(0.5, 2.0, 1);
		*TempoPartidaSTriag1 = Tempo + TempoServico;
		*TempoOcupacaoSTriag1 = *TempoOcupacaoSTriag1 + TempoServico;
		*TempoTotalPermanencia = *TempoTotalPermanencia + TempoServico;
	}

}

void EventoPartida1(float Tempo,
	int *NumClientesSistema,
	int *EstadoSAtend1,
	float **FilaEventosChegadaSAtend,
	float *TempoPartidaSAtend1,
	float *TempoProximaChegadaSTriag,
	float *TempoOcupacaoSAtend1,
	float *TempoTotalEsperaSAtend,
	float *TempoTotalPermanencia)
{
	float	TempoChegadaCliente,
		TempoEsperaCliente,
		TempoServico;

	if (EmptyQueue(*FilaEventosChegadaSAtend))
	{
		*EstadoSAtend1 = 0;
		*TempoPartidaSAtend1 = Infinito;
	}
	else
	{
		TempoChegadaCliente = Front(*FilaEventosChegadaSAtend);
		TempoEsperaCliente = Tempo - TempoChegadaCliente;
		*NumClientesSistema = *NumClientesSistema + 1;
		TempoServico = DeterminarTempoServico(0.5, 2.0, 1);
		*TempoProximaChegadaSTriag = *TempoPartidaSAtend1; //para ir buscar o valor antes deste ser alterado
		*TempoPartidaSAtend1 = Tempo + TempoServico;
		*FilaEventosChegadaSAtend = RemoveQueue(*FilaEventosChegadaSAtend);
		*TempoTotalEsperaSAtend = *TempoTotalEsperaSAtend + TempoEsperaCliente;
		*TempoOcupacaoSAtend1 = *TempoOcupacaoSAtend1 + TempoServico;
		*TempoTotalPermanencia = *TempoTotalPermanencia + TempoServico + TempoEsperaCliente;
	}
}
void EventoPartida2(float Tempo,
	int *NumClientesSistema,
	int *EstadoSAtend2,
	float **FilaEventosChegadaSAtend,
	float *TempoPartidaSAtend2,
	float *TempoProximaChegadaSTriag,
	float *TempoOcupacaoSAtend2,
	float *TempoTotalEsperaSAtend,
	float *TempoTotalPermanencia)
{
	float	TempoChegadaCliente,
		TempoEsperaCliente,
		TempoServico;

	if (EmptyQueue(*FilaEventosChegadaSAtend))
	{
		*EstadoSAtend2 = 0;
		*TempoPartidaSAtend2 = Infinito;
	}
	else
	{
		TempoChegadaCliente = Front(*FilaEventosChegadaSAtend);
		TempoEsperaCliente = Tempo - TempoChegadaCliente;
		*NumClientesSistema = *NumClientesSistema + 1;
		TempoServico = DeterminarTempoServico(0.5, 2.0, 1);
		*TempoPartidaSAtend2 = Tempo + TempoServico;
		*TempoProximaChegadaSTriag = *TempoPartidaSAtend2; //para ir buscar o valor antes deste ser alterado
		*TempoProximaChegadaSTriag = Tempo + TempoServico;
		*FilaEventosChegadaSAtend = RemoveQueue(*FilaEventosChegadaSAtend);
		*TempoTotalEsperaSAtend = *TempoTotalEsperaSAtend + TempoEsperaCliente;
		*TempoOcupacaoSAtend2 = *TempoOcupacaoSAtend2 + TempoServico;
		*TempoTotalPermanencia = *TempoTotalPermanencia + TempoServico + TempoEsperaCliente;
	}
}


void ContadoresEstatisticos(int NumClientesSistema,
	int TotalClientesFilaSAtend,
	float TempoOcupacaoSAtend1,
	float TempoOcupacaoSAtend2,
	float TempoTotalEsperaSAtend,
	float TempoTotalPermanencia,
	float TempoTotalSistema)
{
	int TaxaOcupacaoAgentes,
		TaxaOcupacaoAgente1,
		TaxaOcupacaoAgente2;
	float	NumMedioClientesFila,
		TempoMedioEsperaClientes,
		TempoMedioPermanenciaClientes;

	TaxaOcupacaoAgentes = (TempoOcupacaoSAtend1 + TempoOcupacaoSAtend2) / (2 * TempoTotalSistema) * 100;
	TaxaOcupacaoAgente1 = TempoOcupacaoSAtend1 / TempoTotalSistema * 100;
	TaxaOcupacaoAgente2 = TempoOcupacaoSAtend2 / TempoTotalSistema * 100;
	NumMedioClientesFila = TotalClientesFilaSAtend / (float)NumClientesSistema;
	TempoMedioEsperaClientes = TempoTotalEsperaSAtend / NumClientesSistema;
	TempoMedioPermanenciaClientes = TempoTotalPermanencia / NumClientesSistema;

	printf("TaxaOcupacaoAgentes = %d%%\n", TaxaOcupacaoAgentes);
	printf("TaxaOcupacaoAgente1 = %d%%\n", TaxaOcupacaoAgente1);
	printf("TaxaOcupacaoAgente2 = %d%%\n", TaxaOcupacaoAgente2);
	printf("NumMedioClientesFila = %.3f\n", NumMedioClientesFila);
	printf("TempoMedioEsperaClientes = %.3f\n", TempoMedioEsperaClientes);
	printf("TempoMedioPermanaenciaClientes = %.3f\n", TempoMedioPermanenciaClientes);

}