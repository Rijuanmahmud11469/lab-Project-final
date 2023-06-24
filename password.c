#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LEN 32
#define MAX_PASSWORD_LEN 32

struct User {
  char username[MAX_USERNAME_LEN];
  char password[MAX_PASSWORD_LEN];
};

void read_users_from_file(struct User *users, int *num_users) {
  FILE *fp = fopen("users.txt", "r");
  if (fp == NULL) {
    fprintf(stderr, "Error opening file 'users.txt'\n");
    exit(1);
  }

  int i = 0;
  while (!feof(fp)) {
    fscanf(fp, "%s %s\n", users[i].username, users[i].password);
    i++;
  }

  *num_users = i;
}

int main() {
  struct User users[10];
  int num_users;

  read_users_from_file(users, &num_users);

  char username[MAX_USERNAME_LEN];
  char password[MAX_PASSWORD_LEN];

  printf("Enter username: ");
  scanf("%s", username);

  printf("Enter password: ");
  scanf("%s", password);

  int i;
  for (i = 0; i < num_users; i++) {
    if (strcmp(username, users[i].username) == 0 &&
        strcmp(password, users[i].password) == 0) {
      printf("Login successful!\n");
      break;
    }
  }

  if (i == num_users) {
    printf("Login failed!\n");
  }

  return 0;
}