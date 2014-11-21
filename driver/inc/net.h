#pragma once

struct ds_server {
	struct task_struct	*thread;
	struct socket		*sock;
	struct mutex		lock;
	struct list_head	srv_list;
	struct list_head	con_list;
	struct mutex		con_list_lock;
	int			port;
	int			stopping;
};

struct ds_con {
	struct task_struct 	*thread;
	struct socket 		*sock;
	struct list_head	con_list;
	struct ds_server	*server;
};

int ds_server_start(int port);
int ds_server_stop(int port);
void ds_server_stop_all(void);


