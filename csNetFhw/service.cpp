#include "service.h"

Service::Service()
{
    this->user=new User();
}

Service::~Service(){
    free(this->user);
}
