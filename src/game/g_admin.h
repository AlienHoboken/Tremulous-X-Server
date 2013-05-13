/*
===========================================================================
Copyright (C) 2004-2006 Tony J. White

This file is part of Tremulous.

Tremulous is free software; you can redistribute it
and/or modify it under the terms of the GNU General Public License as
published by the Free Software Foundation; either version 2 of the License,
or (at your option) any later version.

Tremulous is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Tremulous; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
===========================================================================
*/

#ifndef _G_ADMIN_H
#define _G_ADMIN_H

#define AP(x) trap_SendServerCommand(-1, x)
#define CP(x) trap_SendServerCommand(ent-g_entities, x)
#define CPx(x, y) trap_SendServerCommand(x, y)
#define ADMP(x) G_admin_print(ent, x)
#define ADMBP(x) G_admin_buffer_print(ent, x)
#define ADMBP_begin() G_admin_buffer_begin()
#define ADMBP_end() G_admin_buffer_end(ent)

#define MAX_ADMIN_LEVELS 32 
#define MAX_ADMIN_ADMINS 1024
#define MAX_ADMIN_BANS 1024
#define MAX_ADMIN_NAMELOGS 128
#define MAX_ADMIN_NAMELOG_NAMES 5
#define MAX_ADMIN_ADMINLOGS 128
#define MAX_ADMIN_ADMINLOG_ARGS 50
#define MAX_ADMIN_TKLOGS 64
#define MAX_ADMIN_FLAGS 128
#define MAX_ADMIN_COMMANDS 128
#define MAX_ADMIN_CMD_LEN 20
#define MAX_ADMIN_BAN_REASON 50

#define CHAT_MAXCHAN 10
#define CHAT_MAXPASS 12

#define MAX_REPORTS 500

#define MAX_QUESTIONS 500

/*
 * 1 - cannot be vote kicked, vote muted
 * 2 - cannot be censored or flood protected TODO
 * 3 - never loses credits for changing teams
 * 4 - can see team chat as a spectator
 * 5 - can switch teams any time, regardless of balance
 * 6 - does not need to specify a reason for a kick/ban
 * 7 - can call a vote at any time (regardless of a vote being disabled or 
 * voting limitations)
 * 8 - does not need to specify a duration for a ban
 * 9 - can run commands from team chat
 * 0 - inactivity rules do not apply to them
 * ! - admin commands cannot be used on them
 * @ - does not show up as an admin in !listplayers
 * $ - sees all information in !listplayers 
 * # - permanent designated builder
 * ? - sees and can use adminchat
 * & - uses admin stealth
 * ( - sees and uses dev chat
 * Q - is able to !admintest at any level.
 * q - is able to see incagnito admins.
 */

#define ADMF_IMMUNITY '1'
#define ADMF_NOCENSORFLOOD '2' /* TODO */
#define ADMF_TEAMCHANGEFREE '3'
#define ADMF_SPEC_ALLCHAT '4'
#define ADMF_FORCETEAMCHANGE '5'
#define ADMF_UNACCOUNTABLE '6'
#define ADMF_NO_VOTE_LIMIT '7'
#define ADMF_CAN_PERM_BAN '8'
#define ADMF_TEAMCHAT_CMD '9'
#define ADMF_ACTIVITY '0'

#define ADMF_IMMUTABLE '!'
#define ADMF_INCOGNITO '@'
#define ADMF_SEESFULLLISTPLAYERS '$'
#define ADMF_DBUILDER '#'
#define ADMF_ADMINCHAT '?'
#define ADMF_ADMINSTEALTH '&'
#define ADMF_DEVCHAT '('
#define ADMF_FULLADMINTEST 'Q'
#define ADMF_SUPERADMINLIST 'q'

#define MAX_ADMIN_LISTITEMS 20
#define MAX_ADMIN_SHOWBANS 10

#define MAX_ADMIN_MAPLOG_LENGTH 5

// important note: QVM does not seem to allow a single char to be a
// member of a struct at init time.  flag has been converted to char*

typedef struct
{
	char name[ MAX_NAME_LENGTH ];
	char guid[9];
	char reason[ MAX_ADMIN_BAN_REASON ];
	char made[18];
	char reporter[ MAX_NAME_LENGTH ];
    char ip[ 20 ];
	char reporterGuid[9];
	char reporterIp[ 20 ];
	qboolean deleted;
} g_admin_report_t;

/*typedef struct
{
	char question[ 50 ];
	char answer[ 50 ];
} g_admin_question_t;*/

typedef struct
{
  char *keyword;
  qboolean ( * handler ) ( gentity_t *ent, int skiparg );
  char *flag;
  char *function;  // used for !help
  char *syntax;  // used for !help
}
g_admin_cmd_t;

typedef struct g_admin_level
{
  int level;
  char name[ MAX_NAME_LENGTH ];
  char flags[ MAX_ADMIN_FLAGS ];
}
g_admin_level_t;

typedef struct g_admin_admin
{
  char guid[ 33 ];
  char name[ MAX_NAME_LENGTH ];
  int level;
  char flags[ MAX_ADMIN_FLAGS ];
  int seen;
  char chat[ CHAT_MAXCHAN ][ CHAT_MAXPASS ];
}
g_admin_admin_t;

typedef struct g_admin_ban
{
  char name[ MAX_NAME_LENGTH ];
  char guid[ 33 ];
  char ip[ 20 ];
  char reason[ MAX_ADMIN_BAN_REASON ];
  char made[ 18 ]; // big enough for strftime() %c
  int expires;
  char banner[ MAX_NAME_LENGTH ];
}
g_admin_ban_t;

typedef struct g_admin_command
{
  char command[ MAX_ADMIN_CMD_LEN ];
  char exec[ MAX_QPATH ];
  char desc[ 50 ];
  int levels[ MAX_ADMIN_LEVELS + 1 ];
}
g_admin_command_t;

typedef struct g_admin_namelog
{
  char      name[ MAX_ADMIN_NAMELOG_NAMES ][MAX_NAME_LENGTH ];
  char      ip[ 16 ];
  char      guid[ 33 ];
  int       slot;
  qboolean  banned;
}
g_admin_namelog_t;

typedef struct g_admin_adminlog
{
	char      name[ MAX_NAME_LENGTH ];
	char      command[ MAX_ADMIN_CMD_LEN ];
	char      args[ MAX_ADMIN_ADMINLOG_ARGS ];
	int       id;
	int       time;
	int       level;
	qboolean  success;
}
g_admin_adminlog_t;


typedef struct g_admin_tklog
{
	char      name[ MAX_NAME_LENGTH ];
	char      victim[ MAX_NAME_LENGTH ];
	int       id;
	int       time;
	int       damage;
	int       value;
	int       team;
	int       weapon;
}
g_admin_tklog_t;

qboolean G_admin_ban_check( char *userinfo, char *reason, int rlen );
qboolean G_admin_cmd_check( gentity_t *ent, qboolean say );
qboolean G_admin_readconfig( gentity_t *ent, int skiparg );
qboolean G_admin_permission( gentity_t *ent, char flag );
qboolean G_admin_name_check( gentity_t *ent, char *name, char *err, int len );
void G_admin_namelog_update( gclient_t *ent, qboolean disconnect );
void G_admin_maplog_result( char *flag );
int G_admin_level( gentity_t *ent );
void G_admin_set_adminname( gentity_t *ent );
char* G_admin_adminPrintName( gentity_t *ent );

// ! command functions
qboolean G_admin_time( gentity_t *ent, int skiparg );
qboolean G_admin_setlevel( gentity_t *ent, int skiparg );
qboolean G_admin_flaglist( gentity_t *ent, int skiparg );
qboolean G_admin_flag( gentity_t *ent, int skiparg );
qboolean G_admin_kick( gentity_t *ent, int skiparg );
qboolean G_admin_adjustban( gentity_t *ent, int skiparg );
qboolean G_admin_subnetban( gentity_t *ent, int skiparg );
qboolean G_admin_ban( gentity_t *ent, int skiparg );
qboolean G_admin_unban( gentity_t *ent, int skiparg );
qboolean G_admin_putteam( gentity_t *ent, int skiparg );
qboolean G_admin_listadmins( gentity_t *ent, int skiparg );
qboolean G_admin_listlayouts( gentity_t *ent, int skiparg );
qboolean G_admin_listplayers( gentity_t *ent, int skiparg );
qboolean G_admin_listmaps( gentity_t *ent, int skiparg );
qboolean G_admin_listrotation( gentity_t *ent, int skiparg );
qboolean G_admin_map( gentity_t *ent, int skiparg );
qboolean G_admin_devmap( gentity_t *ent, int skiparg );
void G_admin_maplog_update( void );
qboolean G_admin_maplog( gentity_t *ent, int skiparg );
qboolean G_admin_layoutsave( gentity_t *ent, int skiparg );
qboolean G_admin_mute( gentity_t *ent, int skiparg );
qboolean G_admin_denybuild( gentity_t *ent, int skiparg );
qboolean G_admin_showbans( gentity_t *ent, int skiparg );
qboolean G_admin_help( gentity_t *ent, int skiparg );
qboolean G_admin_admintest( gentity_t *ent, int skiparg );
qboolean G_admin_allready( gentity_t *ent, int skiparg );
qboolean G_admin_cancelvote( gentity_t *ent, int skiparg );
qboolean G_admin_passvote( gentity_t *ent, int skiparg );
qboolean G_admin_spec999( gentity_t *ent, int skiparg );
qboolean G_admin_register( gentity_t *ent, int skiparg );
qboolean G_admin_unregister( gentity_t *ent, int skiparg );
qboolean G_admin_rename( gentity_t *ent, int skiparg );
qboolean G_admin_restart( gentity_t *ent, int skiparg );
qboolean G_admin_nextmap( gentity_t *ent, int skiparg );
qboolean G_admin_namelog( gentity_t *ent, int skiparg );
qboolean G_admin_lock( gentity_t *ent, int skiparg );
qboolean G_admin_unlock( gentity_t *ent, int skiparg );
qboolean G_admin_info( gentity_t *ent, int skiparg );
qboolean G_admin_nobuild(gentity_t *ent, int skiparg );
qboolean G_admin_buildlog( gentity_t *ent, int skiparg );
qboolean G_admin_revert( gentity_t *ent, int skiparg );
qboolean G_admin_pause( gentity_t *ent, int skiparg );
qboolean G_admin_L0( gentity_t *ent, int skiparg );
qboolean G_admin_L1( gentity_t *ent, int skiparg );
qboolean G_admin_putmespec( gentity_t *ent, int skiparg );
qboolean G_admin_warn( gentity_t *ent, int skiparg );
qboolean G_admin_designate( gentity_t *ent, int skiparg );
qboolean G_admin_cp( gentity_t *ent, int skiparg );

// Added by dulci
qboolean G_admin_set( gentity_t *ent, int skiparg );

//added by Herm
void G_admin_chat_writeconfig( void );
qboolean G_admin_chat_readconfig( gentity_t *ent );
void G_admin_chat_sync( gentity_t *ent );
void G_admin_chat_update( gentity_t *ent, int chan );
qboolean G_admin_report( gentity_t *ent, int skiparg );
qboolean G_admin_report_load( gentity_t *ent, int skiparg );
qboolean G_admin_report_list( gentity_t *ent, int skiparg );
qboolean G_admin_report_delete( gentity_t *ent, int skiparg );
qboolean G_admin_message(gentity_t *ent, int skiparg);
qboolean G_admin_followers(gentity_t *ent, int skiparg);
qboolean G_admin_inactives(gentity_t *ent, int skiparg );
qboolean G_admin_revertinactives(gentity_t *ent, int skiparg);
qboolean G_admin_muteall( gentity_t *ent, int skiparg );
qboolean G_admin_silentmute( gentity_t *ent, int skiparg );
qboolean G_admin_global( gentity_t *ent, int skiparg );
qboolean G_admin_global_load( gentity_t *ent, int skiparg );
qboolean G_admin_global_save( gentity_t *ent, int skiparg );
qboolean G_admin_global_list( gentity_t *ent, int skiparg );
qboolean G_admin_global_delete( gentity_t *ent, int skiparg );
int G_admin_global_check( char *userinfo );
qboolean G_admin_check( gentity_t *ent, int skiparg );
qboolean G_admin_hideme(gentity_t *ent, int skiparg );
qboolean G_admin_cp_silent( gentity_t *ent, int skiparg);

int G_admin_weblevel( char* guid);
char* G_admin_webname( char* guid);

qboolean G_reconnectdb( gentity_t *ent, int skiparg );

qboolean G_adminDeleteGlobal(gentity_t *ent, int skiparg );
qboolean G_adminListGlobals(gentity_t *ent, int skiparg );
qboolean G_adminGlobalMute(gentity_t *ent, int skiparg );
qboolean G_adminGlobalForcespec(gentity_t *ent, int skiparg );
qboolean G_adminGlobalDenyBuild(gentity_t *ent, int skiparg );
qboolean G_adminGlobalHandicap(gentity_t *ent, int skiparg );
qboolean G_adminGlobalBan(gentity_t *ent, int skiparg );
qboolean G_adminGlobalSync(gentity_t *ent, int skiparg);
qboolean G_adminWhiteList(gentity_t *ent, int skiparg);
qboolean G_adminWhiteDelete(gentity_t *ent, int skiparg);
qboolean G_adminWhiteAdd(gentity_t *ent, int skiparg);
// end herm

qboolean G_admin_fireworks( gentity_t *ent, int skiparg );
qboolean G_admin_credits( gentity_t *ent, int skiparg ); 
qboolean G_admin_demo( gentity_t *ent, int skiparg );
qboolean G_admin_grab( gentity_t *ent, int skiparg );
qboolean G_admin_denyweapon( gentity_t *ent, int skiparg );
qboolean G_admin_drop( gentity_t *ent, int skiparg );
qboolean G_admin_bring( gentity_t *ent, int skiparg );
qboolean G_admin_bubble( gentity_t *ent, int skiparg );
qboolean G_issd( gentity_t *ent, int skiparg );
qboolean G_admin_forcespec( gentity_t *ent, int skiparg );
qboolean G_admin_unforcespec( gentity_t *ent, int skiparg );
qboolean G_buy_nuke( gentity_t *ent, int skiparg );
qboolean G_admin_lockname( gentity_t *ent, int skiparg );
qboolean G_admin_seen(gentity_t *ent, int skiparg );
void G_admin_seen_update( char *guid );
qboolean G_admin_slap( gentity_t *ent, int skiparg );
qboolean G_admin_tklog( gentity_t *ent, int skiparg );
void G_admin_tklog_cleanup( void );
void G_admin_tklog_log( gentity_t *attacker, gentity_t *victim, int meansOfDeath );

qboolean G_admin_adminlog( gentity_t *ent, int skiparg );
void G_admin_adminlog_cleanup( void );
void G_admin_adminlog_log( gentity_t *ent, char *command, char *args, int skiparg, qboolean success );
qboolean G_admin_adminlevels( gentity_t *ent, int skiparg );

void G_admin_print( gentity_t *ent, char *m );
void G_admin_buffer_print( gentity_t *ent, char *m );
void G_admin_buffer_begin( void );
void G_admin_buffer_end( gentity_t *ent );

void G_admin_duration( int secs, char *duration, int dursize );
void G_admin_cleanup( void );
void G_admin_namelog_cleanup( void );

#endif /* ifndef _G_ADMIN_H */
