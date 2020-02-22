#include <sys/io.h>
#include <simpleApp.h>
#include <vrj/Kernel/Kernel.h>

#define DATA 0x378
#define base DATA+2

using namespace std;
using namespace vrj;

int main(int argc, char *argv[]){
	float alpha;
	float beta;
	float gamma;
	
	/*Begin VRJuggler Basic Setup*/
	
	//Allocate the kernel object and the application object
   	Kernel* kernel = Kernel::instance();               // Get the kernel
   	simpleApp* application = new simpleApp();          // Instantiate an instance of the app

   	//If not args passed to the program Display usage information and exit
   	if (argc <= 1){
      		std::cout << "\n\n";
      		std::cout << "Usage: " << argv[0] << " vjconfigfile[0] vjconfigfile[1] ... vjconfigfile[n]" << std::endl;
      		exit(1);
   	}

   	//Load any config files specified on the command line
   	for( int i = 1; i < argc; ++i ){
      		kernel->loadConfigFile(argv[i]);
   	}

   	//Start the kernel running
   	kernel->start();

	//Give the kernel an application to execute
	kernel->setApplication(application);
	
	/*end VRJuggler Basic Setup*/
	
	//get access to ports

	if (ioperm(DATA,3,1)) {
        	printf("Sorry, you were not able to gain access to the ports\n");
        	exit(1);
     	}

	//set parallel port voltage to input data
	outb(32, base);
	//iput data from parallel port
	alpha=inb(DATA);
	usleep(50000);
	beta=inb(DATA);
	usleep(50000);
	gamma=inb(DATA);
	usleep(50000);
	
	/*JR Juggler sets matrix values*/
	application->direction(alpha, beta, gamma);
	sleep(1);
	
	//Keep thread alive and waiting
	kernel->waitForKernelStop();

	//delete app
	delete application;
}
