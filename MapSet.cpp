#include "MapSet.h"

MapSet::MapSet()
{
    id=0;

}
bool MapSet::IsBlocked(){
    if(id == '1'){
        return true;
    }else{
        return false;
    }
}
