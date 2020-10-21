openSidebar() {
  let windowHeight = window.innerHeight;
  let windowWidth = window.innerWidth;
  let listItems = document.getElementsByClassName("list-item");
  document.getElementById('menu-drop').className = "in";
  // document.getElementById('menu-drop').style.transform = 'translateY(0)';
}

closeSidebar() {
  document.getElementById('menu-drop').className = "out";
  // document.getElementById('menu-drop').style.transform = 'translateX(-100%)';
}