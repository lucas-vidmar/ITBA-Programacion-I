void bitSet(int bit, int puerto)
{

switch (puerto)
 {
	case 'a':
		 switch(bit)
		 {
			case 0:
				registro.ab.a.bitrega.b0 = 1;
				break;
			case 1:
				registro.ab.a.bitrega.b1 = 1;
				break;
			case 2:
				registro.ab.a.bitrega.b2 = 1;
				break;
			case 3:
				registro.ab.a.bitrega.b3 = 1;
				break;
			case 4:
				registro.ab.a.bitrega.b4 = 1;
				break;
			case 5:
				registro.ab.a.bitrega.b5 = 1;
				break;
			case 6:
				registro.ab.a.bitrega.b6 = 1;
				break;
			case 7:
				registro.ab.a.bitrega.b7 = 1;
				break;
		 }//fin switch(bit) en puerto a
	break;

	case 'b':
		switch(bit)
		 {
			case 0:
				registro.ab.b.bitregb.b0 = 1;
				break;
			case 1:
				registro.ab.b.bitregb.b1 = 1;
				break;
			case 2:
				registro.ab.b.bitregb.b2 = 1;
				break;
			case 3:
				registro.ab.b.bitregb.b3 = 1;
				break;
			case 4:
				registro.ab.b.bitregb.b4 = 1;
				break;
			case 5:
				registro.ab.b.bitregb.b5 = 1;
				break;
			case 6:
				registro.ab.b.bitregb.b6 = 1;
				break;
			case 7:
				registro.ab.b.bitregb.b7 = 1;
				break;
		 }//fin switch(bit) en puerto b
	break;

	case 'd':
		switch(bit)
		 {
			case 0:
				registro.bitregd.bd0 = 1;
				break;
			case 1:
				registro.bitregd.bd1 = 1;
				break;
			case 2:
				registro.bitregd.bd2 = 1;
				break;
			case 3:
				registro.bitregd.bd3 = 1;
				break;
			case 4:
				registro.bitregd.bd4 = 1;
				break;
			case 5:
				registro.bitregd.bd5 = 1;
				break;
			case 6:
				registro.bitregd.bd6 = 1;
				break;
			case 7:
				registro.bitregd.bd7 = 1;
				break;
			case 8:
				registro.bitregd.bd8 = 1;
				break;
			case 9:
				registro.bitregd.bd9 = 1;
				break;
			case 10:
				registro.bitregd.bd10 = 1;
				break;
			case 11:
				registro.bitregd.bd11 = 1;
				break;
			case 12:
				registro.bitregd.bd12 = 1;
				break;
			case 13:
				registro.bitregd.bd13 = 1;
				break;
			case 14:
				registro.bitregd.bd14 = 1;
				break;
			case 15:
				registro.bitregd.bd15 = 1;
				break;
		 }//fin switch(bit) en puerto d
	break;
 }//fin switch(puerto)
}
