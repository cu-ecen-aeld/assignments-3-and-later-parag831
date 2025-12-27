#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <syslog.h>
#include <unistd.h>
#include <sys/stat.h>


int main(int argc , char* argv[])
{
	openlog(NULL,0,LOG_USER);

	int fd;
	int write_size;

	if(argc!=3)
	{
		syslog(LOG_ERR,"incorrect no. of arguments : %d", argc);
		closelog();
		return 1;
	}

	const char* path = argv[1];
	const char* str = argv[2];

	fd = open(path,O_CREAT|O_RDWR|O_TRUNC ,S_IRWXU|S_IRWXG|S_IRWXO);

	if(fd==-1)
	{
		syslog(LOG_ERR,"failed to open the file");
		closelog();
		return 1;
	}


	write_size = write(fd,str,strlen(str));

	if(write_size<strlen(str))
	{
		syslog(LOG_ERR,"write was unsuccessful");
		close(fd);
		closelog();
		return 1;
	}

	syslog(LOG_DEBUG,"Writing %s  to %s ", str,path);
	close(fd);
	closelog();
	return 0;
}
