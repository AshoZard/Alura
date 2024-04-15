import styles from "./styles.module.css";

export default function LinkButton(props) {
  return (
    <a className={styles.wrapper} href={props.href} target="blank">
      {props.children}
    </a>
  );
}
