/*
**  /!\ This file is generated with the script `scripts/main.py`
**  Do NOT manually modify or create files in the `generated/` folder.
**  Prefer re-running the script: `python main.py`
**  ex:
**
**       $> python main.py
**
**  Copyright 2024 Pierre-Nicolas "Ark'Anoryn" Sormani <arkanoryn@gmail.com>
**  SPDX-License-Identifier: GPL-2.0-or-later
**
*/

#include <string.h>

char *check_chord(char *buffer) {
  if (strcmp("are ", buffer) == 0) {
    return "R+A+E";
  }
  if (strcmp("eat ", buffer) == 0) {
    return "T+A+E";
  }
  if (strcmp("learn ", buffer) == 0) {
    return "N+L+A+E";
  }
  if (strcmp("developer ", buffer) == 0) {
    return "R+D+V+E";
  }
  if (strcmp("ing ", buffer) == 0) {
    return "N+G+I";
  }
  if (strcmp("\bn't ", buffer) == 0) {
    return "N+T+'";
  }
  if (strcmp("\b've ", buffer) == 0) {
    return "V+'+E";
  }
  if (strcmp("\b're ", buffer) == 0) {
    return "R+'+E";
  }
  if (strcmp("\b's ", buffer) == 0) {
    return "S+MAGIC+'";
  }
  if (strcmp("\b'd ", buffer) == 0) {
    return "D+MAGIC+'";
  }
  if (strcmp("\b'll ", buffer) == 0) {
    return "L+MAGIC+'";
  }
  if (strcmp("Hi! ", buffer) == 0) {
    return "MAGIC+H+I";
  }
  if (strcmp("yeah ", buffer) == 0) {
    return "Y+A+E";
  }
  if (strcmp("thank you ", buffer) == 0) {
    return "T+Y+O+U";
  }
  if (strcmp("fuck ", buffer) == 0) {
    return "T+W+F";
  }
  if (strcmp("I've ", buffer) == 0) {
    return "V+E+I";
  }
  if (strcmp("I'm ", buffer) == 0) {
    return "M+I";
  }
  if (strcmp("I'll ", buffer) == 0) {
    return "L+MAGIC+I";
  }
  if (strcmp("god ", buffer) == 0) {
    return "O+G+D";
  }
  if (strcmp("project ", buffer) == 0) {
    return "T+O+E+J";
  }
  if (strcmp("product ", buffer) == 0) {
    return "R+D+P+U";
  }
  if (strcmp("lost ", buffer) == 0) {
    return "L+T+S+O";
  }
  if (strcmp("loose ", buffer) == 0) {
    return "L+S+O+E";
  }
  if (strcmp("A ", buffer) == 0) {
    return "BSPC+A";
  }
  if (strcmp("about ", buffer) == 0) {
    return "T+MAGIC+A";
  }
  if (strcmp("after ", buffer) == 0) {
    return "R+T+F";
  }
  if (strcmp("again ", buffer) == 0) {
    return "G+A+I";
  }
  if (strcmp("against ", buffer) == 0) {
    return "T+S+A+I";
  }
  if (strcmp("all ", buffer) == 0) {
    return "L+MAGIC+A";
  }
  if (strcmp("also ", buffer) == 0) {
    return "L+S+A";
  }
  if (strcmp("and ", buffer) == 0) {
    return "N+D+A";
  }
  if (strcmp("another ", buffer) == 0) {
    return "R+H+A";
  }
  if (strcmp("any ", buffer) == 0) {
    return "N+Y+A";
  }
  if (strcmp("around ", buffer) == 0) {
    return "R+D+A";
  }
  if (strcmp("as ", buffer) == 0) {
    return "A+S";
  }
  if (strcmp("ask ", buffer) == 0) {
    return "S+K+A";
  }
  if (strcmp("at ", buffer) == 0) {
    return "T+A";
  }
  if (strcmp("back ", buffer) == 0) {
    return "B+C+K";
  }
  if (strcmp("be ", buffer) == 0) {
    return "B+E";
  }
  if (strcmp("because ", buffer) == 0) {
    return "B+A+E";
  }
  if (strcmp("become ", buffer) == 0) {
    return "M+C+E";
  }
  if (strcmp("before ", buffer) == 0) {
    return "B+F+O";
  }
  if (strcmp("begin ", buffer) == 0) {
    return "B+G+E+I";
  }
  if (strcmp("between ", buffer) == 0) {
    return "T+W+E";
  }
  if (strcmp("birthday ", buffer) == 0) {
    return "B+D+A";
  }
  if (strcmp("both ", buffer) == 0) {
    return "B+T+H";
  }
  if (strcmp(", but ", buffer) == 0) {
    return "B+U";
  }
  if (strcmp("by ", buffer) == 0) {
    return "B+Y";
  }
  if (strcmp("call ", buffer) == 0) {
    return "L+C+A";
  }
  if (strcmp("can ", buffer) == 0) {
    return "N+C+A";
  }
  if (strcmp("can not ", buffer) == 0) {
    return "N+T+C+A";
  }
  if (strcmp("change ", buffer) == 0) {
    return "C+H+A+E";
  }
  if (strcmp("child ", buffer) == 0) {
    return "L+D+C";
  }
  if (strcmp("come ", buffer) == 0) {
    return "M+C+O";
  }
  if (strcmp("consider ", buffer) == 0) {
    return "N+D+C";
  }
  if (strcmp("could ", buffer) == 0) {
    return "C+O+U";
  }
  if (strcmp("course ", buffer) == 0) {
    return "R+C+O+U";
  }
  if (strcmp("day ", buffer) == 0) {
    return "D+Y+A";
  }
  if (strcmp("develop ", buffer) == 0) {
    return "D+V+E";
  }
  if (strcmp("do ", buffer) == 0) {
    return "D+O";
  }
  if (strcmp("down ", buffer) == 0) {
    return "N+D+W";
  }
  if (strcmp("during ", buffer) == 0) {
    return "N+R+D";
  }
  if (strcmp("each ", buffer) == 0) {
    return "C+H+E";
  }
  if (strcmp("early ", buffer) == 0) {
    return "L+Y+E";
  }
  if (strcmp("end ", buffer) == 0) {
    return "N+D+E";
  }
  if (strcmp("even ", buffer) == 0) {
    return "N+V+E";
  }
  if (strcmp("eye ", buffer) == 0) {
    return "MAGIC+Y+E";
  }
  if (strcmp("face ", buffer) == 0) {
    return "C+F+A";
  }
  if (strcmp("fact ", buffer) == 0) {
    return "T+C+F";
  }
  if (strcmp("feel ", buffer) == 0) {
    return "L+F+E";
  }
  if (strcmp("few ", buffer) == 0) {
    return "W+F+E";
  }
  if (strcmp("find ", buffer) == 0) {
    return "N+D+F";
  }
  if (strcmp("first ", buffer) == 0) {
    return "R+F+I";
  }
  if (strcmp("follow ", buffer) == 0) {
    return "L+F+O";
  }
  if (strcmp("for ", buffer) == 0) {
    return "R+F+O";
  }
  if (strcmp("form ", buffer) == 0) {
    return "M+F+O";
  }
  if (strcmp("from ", buffer) == 0) {
    return "R+M+F";
  }
  if (strcmp("general ", buffer) == 0) {
    return "N+L+E";
  }
  if (strcmp("get ", buffer) == 0) {
    return "T+G+E";
  }
  if (strcmp("give ", buffer) == 0) {
    return "G+E+I";
  }
  if (strcmp("go ", buffer) == 0) {
    return "G+O";
  }
  if (strcmp("good ", buffer) == 0) {
    return "D+MAGIC+G+O";
  }
  if (strcmp("govern ", buffer) == 0) {
    return "N+R+G+O";
  }
  if (strcmp("great ", buffer) == 0) {
    return "R+G+E";
  }
  if (strcmp("group ", buffer) == 0) {
    return "R+G+P";
  }
  if (strcmp("hand ", buffer) == 0) {
    return "N+H+A";
  }
  if (strcmp("have ", buffer) == 0) {
    return "V+H+E";
  }
  if (strcmp("he ", buffer) == 0) {
    return "H+E";
  }
  if (strcmp("head ", buffer) == 0) {
    return "D+H+A+E";
  }
  if (strcmp("help ", buffer) == 0) {
    return "L+H+E";
  }
  if (strcmp("here ", buffer) == 0) {
    return "R+H+E";
  }
  if (strcmp("high ", buffer) == 0) {
    return "G+H+I";
  }
  if (strcmp("hold ", buffer) == 0) {
    return "L+D+H+O";
  }
  if (strcmp("home ", buffer) == 0) {
    return "H+O+E";
  }
  if (strcmp("house ", buffer) == 0) {
    return "S+O+E";
  }
  if (strcmp("how ", buffer) == 0) {
    return "H+O";
  }
  if (strcmp("however ", buffer) == 0) {
    return "W+MAGIC+H+O";
  }
  if (strcmp("I ", buffer) == 0) {
    return "I+MAGIC";
  }
  if (strcmp("if ", buffer) == 0) {
    return "F+I";
  }
  if (strcmp("in ", buffer) == 0) {
    return "N+I";
  }
  if (strcmp("increase ", buffer) == 0) {
    return "N+R+C+I";
  }
  if (strcmp("interest ", buffer) == 0) {
    return "N+R+T+I";
  }
  if (strcmp("into ", buffer) == 0) {
    return "N+T+I";
  }
  if (strcmp("it ", buffer) == 0) {
    return "T+I";
  }
  if (strcmp("just ", buffer) == 0) {
    return "T+S+U+J";
  }
  if (strcmp("keep ", buffer) == 0) {
    return "MAGIC+K+E";
  }
  if (strcmp("know ", buffer) == 0) {
    return "N+W+K";
  }
  if (strcmp("knowledge ", buffer) == 0) {
    return "N+L+W+K";
  }
  if (strcmp("large ", buffer) == 0) {
    return "R+G+A";
  }
  if (strcmp("last ", buffer) == 0) {
    return "L+T+S";
  }
  if (strcmp("late ", buffer) == 0) {
    return "L+T+A";
  }
  if (strcmp("lead ", buffer) == 0) {
    return "L+D+A+E";
  }
  if (strcmp("leave ", buffer) == 0) {
    return "L+E+A";
  }
  if (strcmp("life ", buffer) == 0) {
    return "L+F+I";
  }
  if (strcmp("like ", buffer) == 0) {
    return "L+K+E";
  }
  if (strcmp("line ", buffer) == 0) {
    return "L+E+I";
  }
  if (strcmp("little ", buffer) == 0) {
    return "L+T+I";
  }
  if (strcmp("long ", buffer) == 0) {
    return "N+L+G";
  }
  if (strcmp("look ", buffer) == 0) {
    return "MAGIC+L+K";
  }
  if (strcmp("make ", buffer) == 0) {
    return "M+K+E";
  }
  if (strcmp("man ", buffer) == 0) {
    return "N+M+A";
  }
  if (strcmp("many ", buffer) == 0) {
    return "N+M+Y";
  }
  if (strcmp("may ", buffer) == 0) {
    return "M+Y+A";
  }
  if (strcmp("mean ", buffer) == 0) {
    return "M+A+E";
  }
  if (strcmp("might ", buffer) == 0) {
    return "M+H+I";
  }
  if (strcmp("more ", buffer) == 0) {
    return "R+M+O";
  }
  if (strcmp("most ", buffer) == 0) {
    return "M+S+O";
  }
  if (strcmp("move ", buffer) == 0) {
    return "M+V+E";
  }
  if (strcmp("must ", buffer) == 0) {
    return "T+S+U";
  }
  if (strcmp("nation ", buffer) == 0) {
    return "N+T+A+I";
  }
  if (strcmp("need ", buffer) == 0) {
    return "N+D+MAGIC+E";
  }
  if (strcmp("never ", buffer) == 0) {
    return "N+R+V";
  }
  if (strcmp("new ", buffer) == 0) {
    return "N+W+E";
  }
  if (strcmp("no ", buffer) == 0) {
    return "N+MAGIC";
  }
  if (strcmp("not ", buffer) == 0) {
    return "N+T";
  }
  if (strcmp("now ", buffer) == 0) {
    return "N+W";
  }
  if (strcmp("number ", buffer) == 0) {
    return "N+R+M";
  }
  if (strcmp("of ", buffer) == 0) {
    return "F+O";
  }
  if (strcmp("off ", buffer) == 0) {
    return "MAGIC+F+O";
  }
  if (strcmp("old ", buffer) == 0) {
    return "L+D+O";
  }
  if (strcmp("on ", buffer) == 0) {
    return "N+O";
  }
  if (strcmp("one ", buffer) == 0) {
    return "N+O+E";
  }
  if (strcmp("only ", buffer) == 0) {
    return "L+Y+O";
  }
  if (strcmp("open ", buffer) == 0) {
    return "P+O+E";
  }
  if (strcmp("or ", buffer) == 0) {
    return "R+O";
  }
  if (strcmp("order ", buffer) == 0) {
    return "R+D+O";
  }
  if (strcmp("other ", buffer) == 0) {
    return "O+T+R";
  }
  if (strcmp("out ", buffer) == 0) {
    return "T+O+U";
  }
  if (strcmp("over ", buffer) == 0) {
    return "V+O+E";
  }
  if (strcmp("own ", buffer) == 0) {
    return "N+W+MAGIC+O";
  }
  if (strcmp("part ", buffer) == 0) {
    return "R+T+P+A";
  }
  if (strcmp("people ", buffer) == 0) {
    return "L+P+E";
  }
  if (strcmp("person ", buffer) == 0) {
    return "R+P+E";
  }
  if (strcmp("place ", buffer) == 0) {
    return "C+P+E";
  }
  if (strcmp("plan ", buffer) == 0) {
    return "N+L+P";
  }
  if (strcmp("play ", buffer) == 0) {
    return "L+P+A";
  }
  if (strcmp("point ", buffer) == 0) {
    return "N+T+P";
  }
  if (strcmp("possible ", buffer) == 0) {
    return "P+E+I";
  }
  if (strcmp("present ", buffer) == 0) {
    return "N+R+T";
  }
  if (strcmp("problem ", buffer) == 0) {
    return "B+P";
  }
  if (strcmp("program ", buffer) == 0) {
    return "R+M+P";
  }
  if (strcmp("public ", buffer) == 0) {
    return "L+P+I";
  }
  if (strcmp("real ", buffer) == 0) {
    return "R+MAGIC+E+A";
  }
  if (strcmp("right ", buffer) == 0) {
    return "R+T+G";
  }
  if (strcmp("run ", buffer) == 0) {
    return "N+R+U";
  }
  if (strcmp("same ", buffer) == 0) {
    return "M+S+A";
  }
  if (strcmp("say ", buffer) == 0) {
    return "S+Y+A";
  }
  if (strcmp("school ", buffer) == 0) {
    return "L+S+H";
  }
  if (strcmp("see ", buffer) == 0) {
    return "S+MAGIC+E";
  }
  if (strcmp("seem ", buffer) == 0) {
    return "M+S+E";
  }
  if (strcmp("set ", buffer) == 0) {
    return "T+S+E";
  }
  if (strcmp("she ", buffer) == 0) {
    return "S+H+E";
  }
  if (strcmp("should ", buffer) == 0) {
    return "S+O+U";
  }
  if (strcmp("show ", buffer) == 0) {
    return "S+H+O";
  }
  if (strcmp("since ", buffer) == 0) {
    return "S+I+E";
  }
  if (strcmp("small ", buffer) == 0) {
    return "L+M+A";
  }
  if (strcmp("so ", buffer) == 0) {
    return "S+O";
  }
  if (strcmp("some ", buffer) == 0) {
    return "M+S+O+E";
  }
  if (strcmp("stand ", buffer) == 0) {
    return "N+T+S+A";
  }
  if (strcmp("state ", buffer) == 0) {
    return "S+T+A+E";
  }
  if (strcmp("still ", buffer) == 0) {
    return "L+T+S+I";
  }
  if (strcmp("such ", buffer) == 0) {
    return "S+H+U";
  }
  if (strcmp("system ", buffer) == 0) {
    return "T+S+Y";
  }
  if (strcmp("take ", buffer) == 0) {
    return "T+K+E";
  }
  if (strcmp("tell ", buffer) == 0) {
    return "L+T+E";
  }
  if (strcmp("than ", buffer) == 0) {
    return "T+H+N";
  }
  if (strcmp("that ", buffer) == 0) {
    return "T+H+A";
  }
  if (strcmp("the ", buffer) == 0) {
    return "T+H";
  }
  if (strcmp("their ", buffer) == 0) {
    return "R+T+MAGIC";
  }
  if (strcmp("them ", buffer) == 0) {
    return "T+H+E";
  }
  if (strcmp("then ", buffer) == 0) {
    return "N+T+MAGIC";
  }
  if (strcmp("there ", buffer) == 0) {
    return "R+T+H";
  }
  if (strcmp("these ", buffer) == 0) {
    return "T+S+MAGIC";
  }
  if (strcmp("they ", buffer) == 0) {
    return "T+Y+E";
  }
  if (strcmp("thing ", buffer) == 0) {
    return "N+T+H+I";
  }
  if (strcmp("think ", buffer) == 0) {
    return "T+K+I";
  }
  if (strcmp("this ", buffer) == 0) {
    return "T+S+H";
  }
  if (strcmp("those ", buffer) == 0) {
    return "T+S+O";
  }
  if (strcmp("time ", buffer) == 0) {
    return "T+E+I";
  }
  if (strcmp("to ", buffer) == 0) {
    return "T+O";
  }
  if (strcmp("too ", buffer) == 0) {
    return "T+MAGIC+O";
  }
  if (strcmp("turn ", buffer) == 0) {
    return "N+R+T+U";
  }
  if (strcmp("under ", buffer) == 0) {
    return "R+D+U";
  }
  if (strcmp("up ", buffer) == 0) {
    return "P+U";
  }
  if (strcmp("use ", buffer) == 0) {
    return "S+U";
  }
  if (strcmp("very ", buffer) == 0) {
    return "R+V+Y";
  }
  if (strcmp("want ", buffer) == 0) {
    return "N+T+W";
  }
  if (strcmp("way ", buffer) == 0) {
    return "W+Y+A";
  }
  if (strcmp("we ", buffer) == 0) {
    return "W+E";
  }
  if (strcmp("well ", buffer) == 0) {
    return "L+W+E";
  }
  if (strcmp("what ", buffer) == 0) {
    return "W+H+A";
  }
  if (strcmp("when ", buffer) == 0) {
    return "N+W";
  }
  if (strcmp("where ", buffer) == 0) {
    return "R+W";
  }
  if (strcmp("which ", buffer) == 0) {
    return "W+MAGIC+H+I";
  }
  if (strcmp("while ", buffer) == 0) {
    return "L+W+I";
  }
  if (strcmp("who ", buffer) == 0) {
    return "W+O";
  }
  if (strcmp("why ", buffer) == 0) {
    return "W+Y";
  }
  if (strcmp("will ", buffer) == 0) {
    return "L+W";
  }
  if (strcmp("with ", buffer) == 0) {
    return "T+W";
  }
  if (strcmp("without ", buffer) == 0) {
    return "T+W+H+O+U";
  }
  if (strcmp("word ", buffer) == 0) {
    return "R+D+W";
  }
  if (strcmp("work ", buffer) == 0) {
    return "R+W+K";
  }
  if (strcmp("world ", buffer) == 0) {
    return "L+D+W+O";
  }
  if (strcmp("would ", buffer) == 0) {
    return "L+D+W";
  }
  if (strcmp("write ", buffer) == 0) {
    return "R+T+W+E";
  }
  if (strcmp("year ", buffer) == 0) {
    return "R+Y+A+E";
  }
  if (strcmp("you ", buffer) == 0) {
    return "Y+O+U";
  }
  return NULL;
}
