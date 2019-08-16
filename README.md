# binder_test_native
show how to add a binderService in andorid  native. And show how to use it.

## libbindertest

define IBinderTestService & BnBinderService & BpBinderService

## libbindertestservice

define BinderTestService implements from BnBinderTestService

## binder_test_main

service bin, it should run in init. So we can provide the service after booting. 

## binder_test_client

client, we can run it anytime to call method in BinderTestService

## how to compile in android

we put binder_test in under frameworks.  
Exactly the four party can be put in different places.   