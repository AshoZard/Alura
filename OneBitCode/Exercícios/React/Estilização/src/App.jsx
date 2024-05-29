import StatusText from "./components/StatusText";
import { Subtitle } from "./components/Subtitle";
import Title from "./components/Title";
import styles from "./App.module.css";

function sum(a, b) {
  return a + b;
}

export default function App() {
  return (
    //estilização mais recomendada pois separa estilização em arquivo diferente e possibilita usar o css de uma forma mais completa com animações e estilização para diferentes tamanho de tela.
    <div className={styles.app}>
      <Title />
      <Subtitle />
      <StatusText />
    </div>
  );
}
