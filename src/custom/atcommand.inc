// Copyright (c) rAthena Dev Teams - Licensed under GNU GPL
// For more information, see LICENCE in the main folder

/**
 * Custom Atcommands
 * Place the body of custom atcommands in this file.
 * Format:
 *	ACMD_FUNC(command_name)
 *	{
 *		<code>;
 *	}
 **/
void atcommand_battlestats_sub(int fd, struct map_session_data *sd) {
	status_data *status = status_get_status_data(&sd->bl);
	char output[CHAT_SIZE_MAX];

    #define battlestats_msg(__msg__) (__msg__); clif_displaymessage(fd, output)

	//battlestats_msg(sprintf(output, "Battle Status: %s", sd->status.name));
    clif_displaymessage(fd, "===============================================================");
	clif_displaymessage(fd, "- Status do Personagem");
    clif_displaymessage(fd, "===============================================================");
	battlestats_msg(sprintf(output, "[Ataque] %d + %d", pc_leftside_atk(sd), pc_rightside_atk(sd)));
	battlestats_msg(sprintf(output, "[Ataque Magico] %d + %d", pc_leftside_matk(sd), pc_rightside_matk(sd)));
	battlestats_msg(sprintf(output, "[Precisao] %d", status->hit));
	battlestats_msg(sprintf(output, "[Critico] %d", status->cri / 10));
	battlestats_msg(sprintf(output, "[Defesa] %d + %d", pc_leftside_def(sd), pc_rightside_def(sd)));
	battlestats_msg(sprintf(output, "[Defesa Magica] %d + %d", pc_leftside_mdef(sd), pc_rightside_mdef(sd)));
	battlestats_msg(sprintf(output, "[Esquiva] %d + %d", status->flee, status->flee2 / 10));
	battlestats_msg(sprintf(output, "[Velocidade de Ataque] %d", (2000 - status->amotion) / 10));
    clif_displaymessage(fd, "===============================================================");
	clif_displaymessage(fd, "- Bonus de Ataque Fisico em %");
    clif_displaymessage(fd, "===============================================================");
    if (sd->right_weapon.addsize[SZ_SMALL] + sd->left_weapon.addsize[SZ_SMALL]) {
		battlestats_msg(sprintf(output, "[vs Pequeno] %d%%", sd->right_weapon.addsize[SZ_SMALL] + sd->left_weapon.addsize[SZ_SMALL]));
	}
	if (sd->right_weapon.addsize[SZ_MEDIUM] + sd->left_weapon.addsize[SZ_MEDIUM]) {
		battlestats_msg(sprintf(output, "[vs Medio] %d%%", sd->right_weapon.addsize[SZ_MEDIUM] + sd->left_weapon.addsize[SZ_MEDIUM]));
	}
    if (sd->right_weapon.addsize[SZ_BIG] + sd->left_weapon.addsize[SZ_BIG]) {
		battlestats_msg(sprintf(output, "[vs Grande] %d%%", sd->right_weapon.addsize[SZ_BIG] + sd->left_weapon.addsize[SZ_BIG]));
	}
	if (sd->right_weapon.addsize[SZ_ALL] + sd->left_weapon.addsize[SZ_ALL]) {
		battlestats_msg(sprintf(output, "[vs Todos Tamanhos] %d%%", sd->right_weapon.addsize[SZ_ALL] + sd->left_weapon.addsize[SZ_ALL]));
	}
	if (sd->right_weapon.addrace[RC_PLAYER_HUMAN] + sd->left_weapon.addrace[RC_PLAYER_HUMAN]) {
		battlestats_msg(sprintf(output, "[vs Jogadores (Humano)] %d%%", sd->right_weapon.addrace[RC_PLAYER_HUMAN] + sd->left_weapon.addrace[RC_PLAYER_HUMAN]));
	}
	if (sd->right_weapon.addrace[RC_PLAYER_DORAM] + sd->left_weapon.addrace[RC_PLAYER_DORAM]) {
		battlestats_msg(sprintf(output, "[vs Jogadores (Doram)] %d%%", sd->right_weapon.addrace[RC_PLAYER_DORAM] + sd->left_weapon.addrace[RC_PLAYER_DORAM]));
	}
	if (sd->right_weapon.addrace[RC_ALL] + sd->left_weapon.addrace[RC_ALL]) {
		battlestats_msg(sprintf(output, "[vs Todas as Raças] %d%%", sd->right_weapon.addrace[RC_ALL] + sd->left_weapon.addrace[RC_ALL]));
	}
	if (sd->right_weapon.addclass[CLASS_NORMAL] + sd->left_weapon.addclass[CLASS_NORMAL]) {
		battlestats_msg(sprintf(output, "[vs Monstros]", sd->right_weapon.addclass[CLASS_NORMAL] + sd->left_weapon.addclass[CLASS_NORMAL]));
	}
    if (sd->right_weapon.addclass[CLASS_BOSS] + sd->left_weapon.addclass[CLASS_BOSS]) {
		battlestats_msg(sprintf(output, "[vs Chefes]", sd->right_weapon.addclass[CLASS_BOSS] + sd->left_weapon.addclass[CLASS_BOSS]));
	}
	if (sd->right_weapon.addclass[CLASS_ALL] + sd->left_weapon.addclass[CLASS_ALL]) {
		battlestats_msg(sprintf(output, "[Aumento de Dano Fisico] %d%%", sd->right_weapon.addclass[CLASS_ALL] + sd->left_weapon.addclass[CLASS_ALL]));
	}
    clif_displaymessage(fd, "===============================================================");
	clif_displaymessage(fd, "- Bonus de Ataque Magico em %");
    clif_displaymessage(fd, "===============================================================");
	if (sd->indexed_bonus.magic_addsize[SZ_SMALL]) {
		battlestats_msg(sprintf(output, "[vs Pequeno]  %d%%", sd->indexed_bonus.magic_addsize[SZ_SMALL]));
	}
    if (sd->indexed_bonus.magic_addsize[SZ_MEDIUM]) {
		battlestats_msg(sprintf(output, "[vs Medio] %d%%", sd->indexed_bonus.magic_addsize[SZ_MEDIUM]));
	}
    if (sd->indexed_bonus.magic_addsize[SZ_BIG]) {
		battlestats_msg(sprintf(output, "[vs Grande] %d%%", sd->indexed_bonus.magic_addsize[SZ_BIG]));
	}
	if (sd->indexed_bonus.magic_addsize[SZ_ALL]) {
		battlestats_msg(sprintf(output, "[vs Todos Tamanhos] %d%%", sd->indexed_bonus.magic_addsize[SZ_ALL]));
	}
	if (sd->indexed_bonus.magic_addrace[RC_PLAYER_HUMAN]) {
		battlestats_msg(sprintf(output, "[vs Jogadores (Humano)] %d%%", sd->indexed_bonus.magic_addrace[RC_PLAYER_HUMAN]));
	}
	if (sd->indexed_bonus.magic_addrace[RC_PLAYER_DORAM]) {
		battlestats_msg(sprintf(output, "[vs Jogadores (Doram)] %d%%", sd->indexed_bonus.magic_addrace[RC_PLAYER_DORAM]));
	}
	if (sd->indexed_bonus.magic_addrace[RC_ALL]) {
		battlestats_msg(sprintf(output, "[vs Todas as Raças] %d%%", sd->indexed_bonus.magic_addrace[RC_ALL]));
	}
	if (sd->indexed_bonus.magic_addclass[CLASS_NORMAL]) {
		battlestats_msg(sprintf(output, "[vs Monstros] %d%%", sd->indexed_bonus.magic_addclass[CLASS_NORMAL]));
	}
    if (sd->indexed_bonus.magic_addclass[CLASS_NORMAL]) {
		battlestats_msg(sprintf(output, "[vs Chefes] %d%%", sd->indexed_bonus.magic_addclass[CLASS_NORMAL]));
	}
	if (sd->indexed_bonus.magic_addclass[CLASS_ALL]) {
		battlestats_msg(sprintf(output, "[Aumento de Dano Magico] %d%%", sd->indexed_bonus.magic_addclass[CLASS_ALL]));
	}
	clif_displaymessage(fd, "===============================================================");
	clif_displaymessage(fd, "- Dano Elemental");
    clif_displaymessage(fd, "===============================================================");
	struct {
		const char *format;
		int value;
	} ele_damage_info[] = {
		{ "[Fisico - Neutro] %d%%", sd->right_weapon.addele[ELE_NEUTRAL] + sd->left_weapon.addele[ELE_NEUTRAL] },
        { "[Magico - Neutro] %d%%", sd->indexed_bonus.subele_script[ELE_NEUTRAL] },
		{ "[Fisico - agua] %d%%", sd->right_weapon.addele[ELE_WATER] + sd->left_weapon.addele[ELE_WATER] },
        { "[Magico - agua] %d%%", sd->indexed_bonus.subele_script[ELE_WATER] },
		{ "[Fisico - Fogo] %d%%", sd->right_weapon.addele[ELE_FIRE] + sd->left_weapon.addele[ELE_FIRE] },
        { "[Magico - Fogo] %d%%", sd->indexed_bonus.subele_script[ELE_FIRE] },
		{ "[Fisico - Vento] %d%%", sd->right_weapon.addele[ELE_WIND] + sd->left_weapon.addele[ELE_WIND] },
        { "[Magico - Vento] %d%%", sd->indexed_bonus.subele_script[ELE_WIND] },
		{ "[Fisico - Veneno] %d%%", sd->right_weapon.addele[ELE_POISON] + sd->left_weapon.addele[ELE_POISON] },
        { "[Magico - Veneno] %d%%", sd->indexed_bonus.subele_script[ELE_POISON] },
		{ "[Fisico - Sagrado] %d%%", sd->right_weapon.addele[ELE_HOLY] + sd->left_weapon.addele[ELE_HOLY] },
        { "[Magico - Sagrado] %d%%", sd->indexed_bonus.subele_script[ELE_HOLY] },
		{ "[Fisico - Maldito] %d%%", sd->right_weapon.addele[ELE_DARK] + sd->left_weapon.addele[ELE_DARK] },
        { "[Magico - Maldito] %d%%", sd->indexed_bonus.subele_script[ELE_DARK] },
		{ "[Fisico - Fantasma] %d%%", sd->right_weapon.addele[ELE_WIND] + sd->left_weapon.addele[ELE_WIND] },
        { "[Magico - Fantasma] %d%%", sd->indexed_bonus.subele_script[ELE_WIND] },
		{ "[Fisico - Morto-Vivo] %d%%", sd->right_weapon.addele[ELE_WIND] + sd->left_weapon.addele[ELE_WIND] },
        { "[Magico - Morto-Vivo] %d%%", sd->indexed_bonus.subele_script[ELE_WIND] },
		{ "[Todos] %d%%", sd->indexed_bonus.subele_script[ELE_ALL] },
	};
	for (int i = 0; i < ARRAYLENGTH(ele_damage_info); i++) {
		if (ele_damage_info[i].value == 0)
			continue;
		battlestats_msg(sprintf(output, ele_damage_info[i].format, ele_damage_info[i].value));
	}
    clif_displaymessage(fd, "===============================================================");
	clif_displaymessage(fd, "- Resistencia Elemental");
    clif_displaymessage(fd, "===============================================================");
	struct {
		const char *format;
		int value;
	} ele_resist_info[] = {
		{ "[Neutro] %d%%", sd->indexed_bonus.subele_script[ELE_NEUTRAL] },
		{ "[agua] %d%%", sd->indexed_bonus.subele_script[ELE_WATER] },
		{ "[Terra] %d%%", sd->indexed_bonus.subele_script[ELE_EARTH] },
		{ "[Fogo] %d%%", sd->indexed_bonus.subele_script[ELE_FIRE] },
		{ "[Vento] %d%%", sd->indexed_bonus.subele_script[ELE_WIND] },
		{ "[Veneno] %d%%", sd->indexed_bonus.subele_script[ELE_POISON] },
		{ "[Sagrado] %d%%", sd->indexed_bonus.subele_script[ELE_HOLY] },
		{ "[Maldito] %d%%", sd->indexed_bonus.subele_script[ELE_DARK] },
		{ "[Fantasma] %d%%", sd->indexed_bonus.subele_script[ELE_GHOST] },
		{ "[Morto-Vivo] %d%%", sd->indexed_bonus.subele_script[ELE_UNDEAD] },
		{ "[Todos] %d%%", sd->indexed_bonus.subele_script[ELE_ALL] },
	};
	for (int i = 0; i < ARRAYLENGTH(ele_resist_info); i++) {
		if (ele_resist_info[i].value == 0)
			continue;
		battlestats_msg(sprintf(output, ele_resist_info[i].format, ele_resist_info[i].value));
	}
	clif_displaymessage(fd, "===============================================================");
	clif_displaymessage(fd, "- Resistencia Racial");
    clif_displaymessage(fd, "===============================================================");
	struct {
		const char *format;
		int value;
	} race_resist_info[] = {
		{ "[Amorfo] %d%%", sd->indexed_bonus.subrace[RC_FORMLESS] },
		{ "[Morto-Vivo] %d%%", sd->indexed_bonus.subrace[RC_UNDEAD] },
		{ "[Bruto] %d%%", sd->indexed_bonus.subrace[RC_BRUTE] },
		{ "[Planta] %d%%", sd->indexed_bonus.subrace[RC_PLANT] },
		{ "[Inseto] %d%%", sd->indexed_bonus.subrace[RC_INSECT] },
		{ "[Peixe] %d%%", sd->indexed_bonus.subrace[RC_FISH] },
		{ "[Demonio] %d%%", sd->indexed_bonus.subrace[RC_DEMON] },
		{ "[Humanoide] %d%%", sd->indexed_bonus.subrace[RC_DEMIHUMAN] },
		{ "[Anjo] %d%%", sd->indexed_bonus.subrace[RC_ANGEL] },
		{ "[Dragao] %d%%", sd->indexed_bonus.subrace[RC_DRAGON] },
		{ "[Jogador - Humano] %d%%", sd->indexed_bonus.subrace[RC_PLAYER_HUMAN] },
		{ "[Jogador - Doram] %d%%", sd->indexed_bonus.subrace[RC_PLAYER_DORAM] },
		{ "[Monstros] %d%%", sd->indexed_bonus.subclass[CLASS_NORMAL] },
        { "[Chefes] %d%%", sd->indexed_bonus.subrace[CLASS_BOSS] },
        { "[Todas] %d%%", sd->indexed_bonus.subrace[RC_ALL] },
	};
	for (int i = 0; i < ARRAYLENGTH(race_resist_info); i++) {
		if (race_resist_info[i].value == 0)
			continue;
		battlestats_msg(sprintf(output, race_resist_info[i].format, race_resist_info[i].value));
	}

#undef battlestats_msg
}

ACMD_FUNC(battlestats) {
	nullpo_retr(-1, sd);
	atcommand_battlestats_sub(fd, sd);
	return 0;
}
//ACMD_FUNC(newcommand)
//{
//	clif_displaymessage(fd, "It works!");
//	clif_specialeffect(&sd->bl, EF_HEARTCASTING, AREA);
//	return 0;
//}
