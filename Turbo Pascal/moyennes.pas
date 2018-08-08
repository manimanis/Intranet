
(*******************************************************************************)
(*  Programme :  Calcul de la moyenne d'un élève                               *)
(*-----------------------------------------------------------------------------*)
(*                                                                             *)
(*  Auteur    : MANI Mohamed Anis                                              *)
(*  MAJ       : 10/09/2001                                                     *)
(*                                                                             *)
(*******************************************************************************)

Program Moyennes;

Uses WinCrt;

Const MAX_MOY = 25;

Var Notes : Array [1..MAX_MOY] of real;
    Coef  : Array [1..MAX_MOY] of real;

{*****************************************************}
{ Retourne un entier compris entre BornSup et BornInf }
{*****************************************************}
function Choix_Entier(BornInf, BornSup : integer):integer;
var i : integer;
begin
     repeat
           Write('Entrer un entier compris entre ', BornInf, ' et ', BornSup, ' : ');
           readln(i);
     until (i >= BornInf) And (i <= BornSup);

     Choix_Entier := i;
end;

{*****************************************************}
{ Saisie d'une Note                                   }
{*****************************************************}
procedure Saisir_Note(i : integer);
begin
     Writeln('--- Saisie de la ', i,'ème Note ---');
     Writeln;
     Writeln;
     Write('La Note : ');
     readln(Notes[i]);
     Write('Son Coef : ');
     readln(Coef[i]);
end;

{*****************************************************}
{ Ajout d'une note avec test si on a atteint le maxi. }
{*****************************************************}
procedure Ajout_Note(var NotesCount : integer);
begin
     ClrScr;
     Writeln('----- Ajout d''une Nouvelle Note -----');
     Writeln;
     Writeln;
     if (NotesCount > MAX_MOY) then
     begin
          Writeln('Impossible d''Ajouter une nouvelle note car ce programme supporte');
          Writeln(MAX_MOY, ' Notes au Maximum');
          Readln;
          exit;
     end
        else
     begin
          Inc(NotesCount);
          Saisir_Note(NotesCount);
     end;
         
end;

{*****************************************************}
{ Affichage des Notes                                 }
{*****************************************************}
procedure Afficher_Notes(NotesCount : integer);
var i : integer;
begin
     ClrScr;
     Writeln('----- Liste des Notes Saisies Par l''utilisateur -----');
     Writeln;
     Writeln;
     for i:=1 to NotesCount do
         Writeln(i:2,' - Note = ',Notes[i]:5:2, ' - Coef. = ', Coef[i]:5:2);
end;

{*****************************************************}
{ Modifier une Note                                   }
{*****************************************************}
procedure Modifier_Note(NotesCount : integer);
var i : integer;
begin
     ClrScr;
     Writeln('----- Modifier une Note -----');
     Writeln;
     Writeln;
     if (NotesCount = 0) then
     begin
          Writeln('Aucune note à Modifier, ajouter des notes...');
          Readln;
          exit;
     end
        else
     begin
          Afficher_Notes(NotesCount);
          i := Choix_Entier(1, NotesCount);
          Saisir_Note(i);
     end;
end;

{******************************************************}
{ Supprimer une Note                                   }
{******************************************************}
procedure Supprimer_Note(var NotesCount : integer);
var i, j : integer;
begin
     ClrScr;
     Writeln('----- Supprimer une Note -----');
     Writeln;
     Writeln;
     if (NotesCount = 0) then
     begin
          Writeln('Aucune note à Supprimer, ajouter des notes...');
          Readln;
          exit;
     end
        else
     begin
          Afficher_Notes(NotesCount);
          i := Choix_Entier(1, NotesCount);

          for j:=i + 1 to NotesCount do
          begin
               Notes[j - 1] := Notes[j];
               Coef[j - 1] := Coef[j];
          end;

          dec(NotesCount);
     end;
end;

{******************************************************}
{ Lister les Note                                      }
{******************************************************}
procedure Lister_Notes(NotesCount : integer);
begin
     if (NotesCount = 0) then
         Writeln('Aucune Note à Afficher')
     else
         Afficher_Notes(NotesCount);

     readln;
end;

{******************************************************}
{ Calculer la moyenne                                  }
{******************************************************}
function Moyenne(NotesCount:integer):real;
var ValMoy, ValCoef : real;
    i : integer;
begin
     ValMoy := 0;
     ValCoef := 0;
     for i:=1 to NotesCount do
     begin
         ValMoy := ValMoy + Notes[i] * Coef[i];
         ValCoef := ValCoef + Coef[i];
     end;

     Moyenne := ValMoy / ValCoef;
end;

{*****************************************************}
{ Afficher la Moyenne                                 }
{*****************************************************}
procedure Afficher_Moyenne(NotesCount : integer);
begin
     ClrScr;
     Writeln('----- Affichage de la Moyenne -----');
     Writeln;
     Writeln;
     if (NotesCount = 0) then
     begin
          Writeln('Aucune note pour calculer la moyenne...');
          Readln;
          exit;
     end
        else
     begin
          Writeln('La Moyenne est : ', Moyenne(NotesCount):5:2);
          readln;
     end;
end;

procedure Menu_Principal;
begin
     ClrScr;
     writeln('                  ----- M e n u   P r i n c i p a l -----');
     writeln;
     writeln;
     writeln('--- N o t e s ---');
     Writeln('    0 - Liste des Notes');
     writeln('    1 - Ajouter une Note');
     writeln('    2 - Modifier une Note');
     writeln('    3 - Supprimer une Note');
     writeln;
     writeln('--- M o y e n n e s ---');
     writeln('    4 - Afficher la Moyenne');
     writeln;
     writeln('    5 - Quitter');
     writeln;
end;

procedure Gestion_Menu_Principal(Option : integer;var NotesCount : integer);
begin
     case option of
          0 : Lister_Notes(NotesCount);
          1 : Ajout_Note(NotesCount);
          2 : Modifier_Note(NotesCount);
          3 : Supprimer_note(NotesCount);
          4 : Afficher_Moyenne(NotesCount);
     end;
end;

{*****************************************************}
{        Programme Principal                          }
{*****************************************************}
var choix    : integer;
    NbrNotes : integer;
begin
     NbrNotes := 0;
     repeat
           Menu_Principal;
           choix := Choix_Entier(0, 5);
           Gestion_Menu_Principal(choix, NbrNotes);
     Until (Choix = 5);

     ClrScr;
     Writeln('Merci d''avoir utilisé notre Programme...');
     Writeln('Au revoir...');
end.