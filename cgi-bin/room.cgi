ELF              0�4   0.      4    (      4   4�4�               4  4�4�                    � �\"  \"           \"  \�\�h  �           h"  h�h��   �            H  H�H�D   D         P�td@!  @�@�4   4         Q�td                          /lib/ld-linux.so.2           GNU                        GNU ����b����w�R<�k���             #        )��K��                �              "              F              [              }              b                            i              V              �               ?              �              /              )              !              x              p              U              N    �        <�      libc.so.6 _IO_stdin_used strcpy sprintf fopen __isoc99_sscanf strlen getchar stdout fputs fclose strcat getenv freopen atoi _IO_getc strcmp __libc_start_main __gmon_start__ GLIBC_2.7 GLIBC_2.1 GLIBC_2.0                                      ii   �      ii   �      ii   �       P�
   �  `�  d�  h�  l�  p�  t�  x�  |�  ��	  ��
  ��  ��  ��  ��  ��  ��  ��  ��  S���  ��s.  ��������t�   ��[�     �5X��%\�    �%`�h    ������%d�h   ������%h�h   ������%l�h   �����%p�h    �����%t�h(   �����%x�h0   �����%|�h8   �p����%��h@   �`����%��hH   �P����%��hP   �@����%��hX   �0����%��h`   � ����%��hh   �����%��hp   � ����%��hx   ������%��h�   ������%��h�   �����1�^����PTRh �h��QVh{��o����f�f�f�f�f�f�f��$�f�f�f�f�f�f��ǳ-ĳ��v�    ��tU���hĳ�Ѓ���Ð�t& �ĳ-ĳ���������t�    ��tU���Phĳ�҃���Ít& ��'    �=� uU����|��������f��d����u듍v �    ��t�U���P�҃���u���U������u�t������E��E�    �!�U�E�� ����0��	v�    ��E��E�;E�|׸   �ÍL$����q�U��WQ���   �E�    ��h@����������P�P������E���hO�hQ��������E���h`���������}�c�E����E߈�E��2����E߀}� t�E�;E�|ыE����  ����m���P��h���Ph@�h��h�������� ����h���P����������^���P�E�Ph��h@��]�������i���P��k���Ph����m���P�;���������k���P�Y������E����i���P�D������E��E�    �}� ��  ��E؉���w����E�Ј�E����u��Z������E؃}��uӍ�w����E���  ��J���P��T���Pȟ��w���P����������T���P�������Eԃ���J���P�������EЃ�h���E�P����������   ����^���P�������Ẽ}� ��   ����^���P�Z������EȋEȉ�������EċEș��Ѓ�)ЉE��E�+E��E��E�+EȉE��}� y$���u��u��u��u��u��u�h�������� �.�E�)E�E�E���u��u��u��u��u��u�hl�������� ��h���E�P����������3  �E�EԋE�EЃ��u�h����,���P�{��������u�h�������P�a���������,���P��;���P���������;���������¸    �����ЍP���;����f� , �������P��;���P�u�������;���������¸    �����ЍP���;����f� , ��;���������¸    �����ЍP���;����f� 0 ��h���������� ���Ph>�hQ��������E����u���;���P���������u��������    �e�Y_]�a��f�f�f�f�f�f�f�UW1�VS�����Ù'  ���l$0��������������)�����t'��    �D$8�,$�D$�D$4�D$��������9�u߃�[^_]�����������������  S���3�����''  ��[�     CONTENT_LENGTH r resources.csv  Content-Type:text/html; charset=UTF-8
  %*[^=]%*c%[^&]%*[^=]%*c%[^&]%*[^=]%*c%s %[^+]%*c%s %[^%]%*c%*c%*c%s %[^,]%*c%[^,]%*s    <html><head><link rel="stylesheet" href="/~cisaic/style.css"><title> Room of Requirement </title><script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.0/jquery.min.js"></script><script src="/~cisaic/room.js"></script></head><body><div class="col1"><div class = "instr"><h1> Commands </h1><p> <b>DROP n</b> : Drop n gold from your inventory. 2 gold = 1 mana </br><b>PLAY</b> : Start the spellcasting lesson</br><b>QUIT</b> : Stop the lesson</br><b>EXIT</b> : Drop everything in your inventory and leave the game </br><b>REFRESH</b> : Refresh the page</p></div><div class ="instrGame"><h1> How to play </h1><p> Today we will be learning three different spells. You win if your spell is successful. You have 10 attempts to cast any combination of the three options. Make sure to spell them exactly as they're written below (no pun intended) <br/><b>Expelliarmus</b> : (Easy) Defensive spell that disarms your opponents  <br/><b>Reducto</b> : (Medium) A curse that can be used to blast solid objects to pieces <br/><b>ExpectoPatronum</b> : (Hard) The only known defense against Dementors. Conjure your animal Patronus by thinking of the happiest memory you can. </p></div></div><div class="col2"><h1 class = "title"> Room of Requirement </h1><img class = "room" src="/~cisaic/rmreq.jpg"><div class = "sandbox"><form action = "teleport.py" class="teleport"><input type = "hidden" name = "inventory" value=" %d,%d"><input type = "hidden" name = "url" value = "url"><input type = "submit" value = "NORTH" class="north cardinal"><input type = "submit" value = "EAST" class="east cardinal"><input type = "submit" value = "WEST" class="west cardinal"></form><form action = "/~cisaic/cgi-bin/room.cgi" method = "POST" accept-charset= "utf-8" name ="commandf" id = "#commandf" target="response"><input type = "text" class = "command" name = "command"><input type = "hidden" name = "count" value="0"><input type = "hidden" name = "inventory" value = "%d,%d"><input type = "submit" class = "submit" onclick = "return submitCom();"></form><form action = "teleport.py" class="teleport"><input type = "hidden" name = "inventory" value ="%d,%d"><input type = "hidden" name = "url" value = "url"><input type = "submit" value = "SOUTH" class="south cardinal"></form></div></div><div class="col3"><h1> Interaction </h1><p class="notEnoughGold">You don't have enough gold to do that!</p><iframe name="response" class="response"></iframe></div></body></html> <html><head><link rel="stylesheet" href="/~cisaic/style.css"><title> Room of Requirement </title><script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.0/jquery.min.js"></script><script src="/~cisaic/room.js"></script></head><body><div class="col1"><div class = "instr"><h1> Commands </h1><p> <b>DROP n</b> : Drop n gold from your inventory. 2 gold = 1 mana </br><b>PLAY</b> : Start the spellcasting lesson</br><b>QUIT</b> : Stop the lesson</br><b>EXIT</b> : Drop everything in your inventory and leave the game </br><b>REFRESH</b> : Refresh the page</p></div><div class ="instrGame"><h1> How to play </h1><p> Today we will be learning three different spells. You win if your spell is successful. You have 10 attempts to cast any combination of the three options. Make sure to spell them exactly as they're written below (no pun intended) <br/><b>Expelliarmus</b> : (Easy) Defensive spell that disarms your opponents  <br/><b>Reducto</b> : (Medium) A curse that can be used to blast solid objects to pieces <br/><b>ExpectoPatronum</b> : (Hard) The only known defense against Dementors. Conjure your animal Patronus by thinking of the happiest memory you can. </p></div></div><div class="col2"><h1 class = "title"> Room of Requirement </h1><img class = "room" src="/~cisaic/rmreq.jpg"><div class = "sandbox"><form action = "teleport.py" class="teleport"><input type = "hidden" name = "inventory" value=" %d,%d"><input type = "hidden" name = "url" value = "url"><input type = "submit" value = "NORTH" class="north cardinal"><input type = "submit" value = "EAST" class="east cardinal"><input type = "submit" value = "WEST" class="west cardinal"></form><form action = "/~cisaic/cgi-bin/room.cgi" method = "POST" accept-charset= "utf-8" name ="commandf" id = "#commandf" target="response"><input type = "text" class = "command" name = "command"><input type = "hidden" name = "count" value="0"><input type = "hidden" name = "inventory" value = "%d,%d"><input type = "submit" class = "submit" onclick = "return submitCom();"></form><form action = "teleport.py" class="teleport"><input type = "hidden" name = "inventory" value ="%d,%d"><input type = "hidden" name = "url" value = "url"><input type = "submit" value = "SOUTH" class="south cardinal"></form></div></div><div class="col3"><h1> Interaction </h1><iframe name="response" class="response"></iframe></div></body></html> %d <html><head><link rel="stylesheet" href="/~cisaic/style.css"><title> Gryffindor Common Room </title></head><body><div class = "bg"><div class="col1"></div><div  class="col2"><h1 style="color:white;margin-top:10%%;"> Goodness, is that the time?! You should hurry back to your common room before the Inquisetorial squad comes prowling! </h1></div><div class="col3"></div></div></body></html> w ;0      ����L   ����p   ;����   p����   ����         zR |�         l���0   FJtx ?;*2$"   @   s���P    A�BL� 4   `   ����'   D Gu Duxu|� A�A�C   8   �   ����a    A�A�C�A�N0HA�A�A�A�   �   ����            ���             ؄   $�   \�         `�      ���o��    �   ��
   �                   T�   �            H�   8�            ���o�����o   ���õ                                                    h�        �&�6�F�V�f�v���������ƅօ�����&�        DROP      EXIT      GCC: (Debian 4.9.2-10) 4.9.2 GCC: (Debian 4.8.4-1) 4.8.4  .symtab .strtab .shstrtab .interp .note.ABI-tag .note.gnu.build-id .gnu.hash .dynsym .dynstr .gnu.version .gnu.version_r .rel.dyn .rel.plt .init .text .fini .rodata .eh_frame_hdr .eh_frame .init_array .fini_array .jcr .dynamic .got .got.plt .data .bss .comment                      4�          H�          h�          ��          ��           �          ̃          ��          8�     	     H�     
     ؄           �          0�          $�          8�          @�          t�          \�          `�          d�          h�          P�          T�          ��           �                                ��   d�         p�      .   ��      A   ��      W   �     f   `�      �    �      �   \�      �            ��            ���   X�      �   d�                   ���   `�       �   h�      �   \�         T�         �     ,  �     2             D  ��
     I              e  `�    {  ��       �             �  +�P     �             �  ĳ      �             �  $�      �  @�n     �             �             �                          !  ��      .             >              M  ��     Z  <�     i             {             �  ��
     �  ��a     �             �             �  $�      �  0�      �  8�     �   �     �  ĳ      
  {�'      ��d                   )             <             L  ĳ     X              r             �             �  ؄       crtstuff.c __JCR_LIST__ deregister_tm_clones register_tm_clones __do_global_dtors_aux completed.6279 __do_global_dtors_aux_fini_array_entry frame_dummy __frame_dummy_init_array_entry room.c __FRAME_END__ __JCR_END__ __init_array_end _DYNAMIC __init_array_start _GLOBAL_OFFSET_TABLE_ __libc_csu_fini count strcmp@@GLIBC_2.0 comD _ITM_deregisterTMCloneTable __x86.get_pc_thunk.bx data_start printf@@GLIBC_2.0 isnInt getchar@@GLIBC_2.0 _edata fclose@@GLIBC_2.1 _fini spell _IO_getc@@GLIBC_2.0 strcat@@GLIBC_2.0 strcpy@@GLIBC_2.0 getenv@@GLIBC_2.0 __data_start puts@@GLIBC_2.0 __gmon_start__ __dso_handle _IO_stdin_used strlen@@GLIBC_2.0 __libc_start_main@@GLIBC_2.0 comE __libc_csu_init __isoc99_sscanf@@GLIBC_2.7 fopen@@GLIBC_2.1 _end _start _fp_hw stdout@@GLIBC_2.0 __bss_start main usrin _Jv_RegisterClasses sprintf@@GLIBC_2.0 atoi@@GLIBC_2.0 __TMC_END__ _ITM_registerTMCloneTable freopen@@GLIBC_2.0 fputs@@GLIBC_2.0 _init                                                  4�4                    #         H�H                     1         h�h  $                  D   ���o   ���  $                N         ���  P              V          �   �                  ^   ���o   ̃�  *                k   ���o   ���  @                z   	      8�8                  �   	   B   H�H  �               �         ؄�  #                  �          �   0                �         0�0  �                 �         $�$                    �         8�8                   �         @�@!  4                  �         t�t!  �                  �         \�\"                    �         `�`"                    �         d�d"                    �         h�h"  �                �         P�P#                   �         T�T#  T                 �         ���#                    �          ��#  $          @       �      0       �#  9                               �#                                 %  �     -         	              �*  �                 