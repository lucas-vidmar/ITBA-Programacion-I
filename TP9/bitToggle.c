int bitToggle(int bit, int puerto)
{
switch (puerto)
 {
	case 'a':
		 switch(bit)
		 {
			case 0:
				registro.ab.a.bitrega.b0 = ~(registro.ab.a.bitrega.b0);
				break;
			case 1:
				registro.ab.a.bitrega.b1 = ~(registro.ab.a.bitrega.b1);
				break;
			case 2:
				registro.ab.a.bitrega.b2 = ~(registro.ab.a.bitrega.b2);
				break;
			case 3:
				registro.ab.a.bitrega.b3 = ~(registro.ab.a.bitrega.b3);
				break;
			case 4:
				registro.ab.a.bitrega.b4 = ~(registro.ab.a.bitrega.b4);
				break;
			case 5:
				registro.ab.a.bitrega.b5 = ~(registro.ab.a.bitrega.b5);
				break;
			case 6:
				registro.ab.a.bitrega.b6 = ~(registro.ab.a.bitrega.b6);
				break;
			case 7:
				registro.ab.a.bitrega.b7 = ~(registro.ab.a.bitrega.b7);
				break;
		 }//fin switch(bit) en puerto a
	break;

	case 'b':
		switch(bit)
		 {
			case 0:
				registro.ab.b.bitregb.b0 = ~(registro.ab.b.bitregb.b0);
				break;
			case 1:
				registro.ab.b.bitregb.b1 = ~(registro.ab.b.bitregb.b1);
				break;
			case 2:
				registro.ab.b.bitregb.b2 = ~(registro.ab.b.bitregb.b2);
				break;
			case 3:
				registro.ab.b.bitregb.b3 = ~(registro.ab.b.bitregb.b3);
				break;
			case 4:
				registro.ab.b.bitregb.b4 = ~(registro.ab.b.bitregb.b4);
				break;
			case 5:
				registro.ab.b.bitregb.b5 = ~(registro.ab.b.bitregb.b5);
				break;
			case 6:
				registro.ab.b.bitregb.b6 = ~(registro.ab.b.bitregb.b6);
				break;
			case 7:
				registro.ab.b.bitregb.b7 = ~(registro.ab.b.bitregb.b7);
				break;
		 }//fin switch(bit) en puerto b
	break;

	case 'd':
		switch(bit)
		 {
			case 0:
				registro.bitregd.bd0 = ~(registro.bitregd.bd0);
				break;
			case 1:
				registro.bitregd.bd1 = ~(registro.bitregd.bd1);
				break;
			case 2:
				registro.bitregd.bd2 = ~(registro.bitregd.bd2);
				break;
			case 3:
				registro.bitregd.bd3 = ~(registro.bitregd.bd3);
				break;
			case 4:
				registro.bitregd.bd4 = ~(registro.bitregd.bd4);
				break;
			case 5:
				registro.bitregd.bd5 = ~(registro.bitregd.bd5);
				break;
			case 6:
				registro.bitregd.bd6 = ~(registro.bitregd.bd6);
				break;
			case 7:
				registro.bitregd.bd7 = ~(registro.bitregd.bd7);
				break;
			case 8:
				registro.bitregd.bd8 = ~(registro.bitregd.bd8);
				break;
			case 9:
				registro.bitregd.bd9 = ~(registro.bitregd.bd9);
				break;
			case 10:
				registro.bitregd.bd10 = ~(registro.bitregd.bd10);
				break;
			case 11:
				registro.bitregd.bd11 = ~(registro.bitregd.bd11);
				break;
			case 12:
				registro.bitregd.bd12 = ~(registro.bitregd.bd12);
				break;
			case 13:
				registro.bitregd.bd13 = ~(registro.bitregd.bd13);
				break;
			case 14:
				registro.bitregd.bd14 = ~(registro.bitregd.bd14);
				break;
			case 15:
				registro.bitregd.bd15 = ~(registro.bitregd.bd15);
				break;
		 }//fin switch(bit) en puerto d
	break;
 }//fin switch(puerto)
}

