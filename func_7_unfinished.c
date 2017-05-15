//função 7
//Listar alunos inscritos num exame

void imprime_num_aluno(Next_aluno lista) {
  Next_aluno aux;
  aux = lista;
  int i=1;
  while(aux != NULL) {
    printf("%d. %d\n", i, aux->num_aluno);
    i++;
    aux = aux->next;
  }
}

void listar_alunos(Next_exame lista_exames) {
  Next_exame l_exames = lista_exames;
  Next_aluno l_alunos
  Next_ptrs_aluno inscritos;
  char *ptr, c;
  int i=1, num;
  printf("Seleccione o exame do qual quer listar os alunos: ");
  while (l_exames) {
    ptr = (l_exames->disciplina)->nome;
    printf("\n%d. ", i);
    i++;
    imprime_array(ptr);
    ptr = l_exames->epoca;
    printf (", ");
    imprime_array(ptr);
    l_exames = l_exames->next;
  }
	
  l_exames = lista_exames->next;
  printf("\nOpcao: ");
  scanf("%d", &num)
  for (i=0; i<num; i++) {
    l_exames = l_exames->next; //agora ja estamos no exame que queremos. basta listar os alunos que estao dentro deste exame
  }
  
  inscritos = l_exames->inscritos;
  printf("ALunos inscritos no exame:\n");
  imprime_num_aluno(inscritos->aluno); //aqui deve entrar "inscritos->aluno" ou só "inscritos"?
 

}
