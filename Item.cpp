#include "Item.h"
#include "Pokemon.h"
#include "Type.h"
#include "Nature.h"
#include "stdio.h"
#include "Data.h"

void Pokemon::setItem(Item _item)
{
	if (item != EMPTY)
	{
		printf("�Ѿ����е���%s,�޷�Я���µĵ���%s", Data::ItemName[(int)item], Data::ItemName[(int)_item]);
		return;
	}
	item = _item;
	switch (item)
	{
	case AssaultVest:
		HitPoints[4] += (HitPoints[4] >> 1);
		break;
	case ChoiceBand:
		HitPoints[1] += (HitPoints[1] >> 1);
		break;
	case ChoiceScarf:
		HitPoints[5] += (HitPoints[5] >> 1);
		break;
	case ChoiceSpecs:
		HitPoints[3] += (HitPoints[3] >> 1);
		break;
	default:;
	}
}

void Pokemon::releaseItem(bool information)
{
	switch (item)
	{
	case AssaultVest:
	case ChoiceBand:
	case ChoiceScarf:
	case ChoiceSpecs:
		calculatePoints();
		break;
	default:;
	}
	item = EMPTY;
}
