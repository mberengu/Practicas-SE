
#include <iostream>
#include <windows.h>
#include <Dshow.h>
//#include "qedit.h"
//#include "atlbase.h"

using namespace std;
void main()
{
	int option;
    IGraphBuilder *pGraph = NULL;  //Creem l'apuntador al graf de filtres
	IMediaControl *pControl = NULL; //creem l'apuntador a un controlador per ayurar i iniciar el graf 
	IMediaEvent *pEvent = NULL; // apunta a l'objecte necessari per obtenir events del filter graph manager
	//IBaseFilter *pGrabberF = NULL;
    //ISampleGrabber *pGrabber = NULL;

	HRESULT hr = CoInitialize(NULL); // Inicialitzem la llibreria COM
	if ( FAILED(hr) ){
		printf("ERROR - Could not initialize COM library");
        return;
	}
	// Create the filter graph manager and query for interfaces.
    hr = CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC_SERVER, IID_IGraphBuilder, (void **)&pGraph);
    if (FAILED(hr))
    {
        printf("ERROR - Could not create the Filter Graph Manager.");
        return;
    }
	
    hr = pGraph->QueryInterface(IID_IMediaControl, (void **)&pControl);
    hr = pGraph->QueryInterface(IID_IMediaEvent, (void **)&pEvent);

    // Build the graph. IMPORTANT: Change this string to a file on your system.
	cout<<"introduce 1:chicken 2:futbol 3: video futbol audio chicken: \n";
	cin>>option;
	switch(option)
	{
		case 1: hr = pGraph->RenderFile(L"C:\\Users\\Victor\\Downloads\\chicken.wmv", NULL);
			
			break;
		case 2: hr = pGraph->RenderFile(L"C:\\Users\\Victor\\Downloads\\futbol.mpg", NULL);
			break;
		case 3:  // Create the Sample Grabber filter.
  			break;
	}

    if (SUCCEEDED(hr))
    {
        // Run the graph.
        hr = pControl->Run();
        if (SUCCEEDED(hr))
        {
            // Wait for completion.
            long evCode;
            pEvent->WaitForCompletion(INFINITE, &evCode);

            // Note: Do not use INFINITE in a real application, because it
            // can block indefinitely.
        }
    }
    pControl->Release();
    pEvent->Release();
    pGraph->Release();
    CoUninitialize();

}