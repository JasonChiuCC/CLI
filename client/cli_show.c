#include "cliincludes.h"
#include "clicmd.h"

void cli_service_show(
	             char *args,
	             int args_len,
	             struct cli_commands *cmd,
	             void *priv);

void cli_service_help_show_date(
				 int tab_level,
				 struct cli_commands *cmd,
				 void *priv);

void cli_service_help_show_cli_version(
				 int tab_level, 
				 struct cli_commands *cmd,
				 void *priv);

void cli_service_help_show(
				 struct cli_commands *cmd,
				 void *priv);

void cli_service_show_date(
				 char *args,
				 int args_len,
				 struct cli_commands *cmd,
				 void *priv);

void cli_service_show_cli_version(
				 char *args,
				 int args_len,
				 struct cli_commands *cmd,
				 void *priv);

struct cli_commands show_subcmd[] = {
	{
		"date",
		cli_service_help_show_date,
		cli_service_show_date,
		NULL,
		0
	},

	{
		"cli_version",
		cli_service_help_show_cli_version,
		cli_service_show_cli_version,
		NULL,
		0
	},
};

struct cli_commands show_cmd[] = {
	"show",
	cli_service_help_show,
	cli_service_show,
	show_subcmd,
	sizeof(show_subcmd) / sizeof(show_subcmd[0])
};

void cli_service_show_cli_version(
						 char *args,
						 int args_len,
						 struct cli_commands *cmd,
						 void *priv
						 		 )
{

}

void cli_service_show_date(
						 char *args,
						 int args_len,
						 struct cli_commands *cmd,
						 void *priv
						  )
{

}

void cli_service_show(
					 char *args,
					 int args_len,
					 struct cli_commands *cmd,
					 void *priv
					 )
{

}

void cli_service_help_show_date(
						 int tab_level,
						 struct cli_commands *cmd,
						 void *priv
						 	   )
{
	fprintf(stderr, "date <show the current system date>\n");
}

void cli_service_help_show_cli_version(
						 int tab_level,
						 struct cli_commands *cmd,
						 void *priv
						 			  )
{
	fprintf(stderr, "version <show the cli version>\n");
}

void cli_service_help_show(struct cli_commands *cmd, void *priv)
{
	fprintf(stderr, "show <sub commands>\n");
	if (cmd->sub_cmd) {
		struct cli_commands *scmd;
		int i;

		scmd = cmd->sub_cmd;
		for (i = 0; cmd->sub_cmd_len; i++) {
			cmd->helpmsg(1, &scmd[i], priv);
		}	
	}
}