/**
 * www.ProtoBlue.com/
 * main.go
 * --------------------------------
 * Created by Lance T. Walker on 11/12/2018
 * Copyright © 2018 CodeLife Productions. All rights reserved.
 */

package main

/* Setup: Frameworks */
import(
  // native:
  "fmt"
  "net/http"
  A "ProtoBlueWebsite/assets"
  // remote:
  "github.com/gorilla/mux"
);

/* Setup: Declarations */

/* Functions: Main */
func init() {

  fmt.Printf("main.go: initializing");
}

func newRouter() *mux.Router {
  r := mux.NewRouter();
  r.HandleFunc("/", handler).Methods("GET");

  staticFileDirectory := http.Dir("./public/");
  staticFileHandler := http.StripPrefix("/public/", http.FileServer(staticFileDirectory));
  r.PathPrefix("/public/").Handler(staticFileHandler).Methods("GET");

  fmt.Printf("main.go: adding router: %v", r);
  return r;
}

func main() {
  r := newRouter();
  http.ListenAndServe(":3000", r);
}

func handler(w http.ResponseWriter, r *http.Request) {

  fmt.Fprintf(w, "handler");
}
