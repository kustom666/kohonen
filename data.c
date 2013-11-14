#include "data.h"

void InitialiseSet(Data **inData)
{
	for(int i =0; i<20; i++){
		Data buffData;
		buffData.a = 0;
		buffData.b = 0;
		*inData[i] = buffData;
	}
}