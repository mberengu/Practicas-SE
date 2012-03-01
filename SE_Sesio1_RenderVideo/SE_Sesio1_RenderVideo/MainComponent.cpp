#include "MainComponent.h"

MainComponent::MainComponent(){
	
}

MainComponent::~MainComponent(){
}

void MainComponent::main(void){
	IGraphBuilder *pGraph = NULL;
	IMediaControl *pControl = NULL;
	IMediaEvent *pEvent = NULL;

	HRESULT hr = CoInitialize(NULL);
	if ( FAILED(hr) ){
		printf("ERROR - Could not initialize COM library");
        return;
	}
}