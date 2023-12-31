// Fill out your copyright notice in the Description page of Project Settings.

#include "Threads/HTTP_Thread_Workflow.h"
#include "FF_HTTP_Advance.h"

// UE Includes.
#include "Async/Async.h"

FHTTP_Thread_Workflow::FHTTP_Thread_Workflow(AHTTP_Server_Advance* In_Parent_Actor)
{
	this->Parent_Actor = In_Parent_Actor;
	
	this->Server_Address_HTTP = "http://0.0.0.0:" + FString::FromInt(this->Parent_Actor->Port_HTTP);
	this->Server_Address_HTTPS = "https://0.0.0.0:" + FString::FromInt(this->Parent_Actor->Port_HTTPS);
}

FHTTP_Thread_Workflow::~FHTTP_Thread_Workflow()
{

}

bool FHTTP_Thread_Workflow::Init()
{
	return true;
}

uint32 FHTTP_Thread_Workflow::Run()
{
	return 0;
}

void FHTTP_Thread_Workflow::Stop()
{

}

void FHTTP_Thread_Workflow::Toggle(bool bIsPause)
{

}

void FHTTP_Thread_Workflow::Callback_HTTP_Start()
{

}